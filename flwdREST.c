#include <string.h>
#include <ctype.h>
#include <jansson.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../../src/ulfius.h"

#define PORT 4437
#define PREFIX "/flwd"

/**
 * callback functions declaration
 */
int callback_flwd (const struct _u_request * request, struct _u_response * response, void * user_data);
int callback_default (const struct _u_request * request, struct _u_response * response, void * user_data);

const char * get_flwd_value(const struct _u_map * map) {
    return u_map_get(map, "flwd");
}
void all_upper(char * value) {

  // Convert to upper case
  char *s = value;
  int i = 0;
  while (*s) {
    *s = toupper((unsigned char) *s);
    if (i == 4) {
      *s =0;
      return;
      }
    s++;i++;
  }
}

int main (int argc, char **argv) {
  int ret;
  
  // Set the framework port number
  struct _u_instance instance;
  
  y_init_logs("flwdREST", Y_LOG_MODE_CONSOLE, Y_LOG_LEVEL_DEBUG, NULL, "Starting flwdREST");
  
  if (ulfius_init_instance(&instance, PORT, NULL) != U_OK) {
    y_log_message(Y_LOG_LEVEL_ERROR, "Error ulfius_init_instance, abort");
    return(1);
  }
  
  u_map_put(instance.default_headers, "Access-Control-Allow-Origin", "*");
  
  // Maximum body size sent by the client is 1 Kb
  instance.max_post_body_size = 1024;
  
  // Endpoint declaration
  ulfius_add_endpoint_by_val(&instance, "POST", PREFIX, "/:flwd", NULL, NULL, NULL, &callback_flwd, "user data 2");
  ulfius_set_default_endpoint(&instance, NULL, NULL, NULL, &callback_default, NULL);

  // Start the framework
  // Open an http connection
  ret = ulfius_start_framework(&instance);
  
  if (ret == U_OK) {
    y_log_message(Y_LOG_LEVEL_DEBUG, "Start %sframework on port %d", ((argc == 4 && strcmp("-secure", argv[1]) == 0)?"secure ":""), instance.port);
    
    // Wait for the user to press <enter> on the console to quit the application
    getchar();
  } else {
    y_log_message(Y_LOG_LEVEL_DEBUG, "Error starting framework");
  }
  y_log_message(Y_LOG_LEVEL_DEBUG, "End framework");
  
  y_close_logs();
  
  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);

  // DO NOT CALL system()
  system("./call_py2 alphanum4_test clear");
  
  return 0;
}


/**
 */
int callback_flwd(const struct _u_request * request, struct _u_response * response, void * user_data) {

  char command[50];
  char word [50];
  sprintf(word, "%s", get_flwd_value(request->map_url));
  all_upper(word);
  sprintf(command, "./call_py2 alphanum4_test flwd %s", word);
//printf("%s\n", word);
//printf(command);
//printf("\n");

  // DO NOT CALL system()
  // If program is run with elevated privilege, cacker could replace call_py2 with whatever they want
  // https://www.securecoding.cert.org/confluence/pages/viewpage.action?pageId=2130132
  system(command);
  response->status = 200;

  return U_OK;
}

/**
 * Default callback function called if no endpoint has a match
 */
int callback_default (const struct _u_request * request, struct _u_response * response, void * user_data) {
  response->string_body = strdup("Page not found - sorry.");
  response->status = 404;
  return U_OK;
}
