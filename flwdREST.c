#include <string.h>
#include <jansson.h>

#include "../../src/ulfius.h"
/*

http://192.168.1.197:7447/flwd
POST
body:
{
  "flwd": "Cats"
}
headers:
Content-Type  application/json

*/

#define PORT 7447
#define PREFIX "/flwd"

// Callback function used to set a new four letter word
int callback_flwd (const struct _u_request * request, struct _u_response * response, void * user_data);

/**
 * Main function
 */
int main (int argc, char **argv) {
 
  char buffer[30]; 
  
  // Initialize the instance
  struct _u_instance instance;
  
  if (ulfius_init_instance(&instance, PORT, NULL) != U_OK) {
    y_log_message(Y_LOG_LEVEL_ERROR, "Error ulfius_init_instance, abort");
    return(1);
  }
  
  // Max post param size is 16 Kb, which means an uploaded file is no more than 16 Kb
  instance.max_post_param_size = 16*1024;
  
  // Endpoint declaration
  ulfius_add_endpoint_by_val(&instance, "POST", PREFIX, NULL, NULL, NULL, NULL, &callback_flwd, &buffer);
  
  // Start the framework
  if (ulfius_start_framework(&instance) == U_OK) {
    printf("Start flwd service on port %d\n", instance.port);
    
    // Wait for the user to press <enter> on the console to quit the application
    getchar();
  } else {
    printf("Error starting framework\n");
  }

  printf("End framework\n");
  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);
  
  return 0;
}

int callback_flwd (const struct _u_request * request, struct _u_response * response, void * user_data) {

char * json_params = json_dumps(request->json_body, JSON_INDENT(2));
printf("%s\n", json_params);
free(json_params);

  response->status = 200;
  return U_OK;
}

