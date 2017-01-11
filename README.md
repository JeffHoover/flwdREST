Web Framework for REST API in C  
https://github.com/babelouest/ulfius  
  
built and installed at:  
~/ulfius/  

clone this repo (flwdREST) into:  
~/ulfius/examples/flwdREST/  
  
--------------  
REST Server:  
  
make test  
2017-01-11T01:08:57 - flwdREST INFO: Starting flwdREST  
2017-01-11T01:08:57 - flwdREST DEBUG: Start framework on port 4437  
  
While the service is running, use a REST client to send a POST to:  
http://192.168.1.197:4437/flwd/test  
  
When you do, the console on the server will say:  
    Set this word on the FLWD: TEST  

Press <enter> to end the service  
2017-01-11T01:08:58 - flwdREST DEBUG: End framework  
  
--------------  
Simple call to inline python:  

g++ $(python-config --includes --libs) call_py.c -lpython2.7 -o call_py  
./call_py  
output will be:  
   hello  
  
--------------  
g++ $(python-config --includes --libs) call_ext_py.c -lpython2.7 -o call_ext_py  
./call_ext_py func.py printme  
  
CURRENTLY segfault'ing :(  
even with suggestion from:  
http://stackoverflow.com/a/8859538/73826 


