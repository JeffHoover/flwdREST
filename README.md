https://github.com/JeffHoover/flwdREST  
~/ulfius/examples/flwdREST  
need ulfius built and installed for REST server  
  
# REST Server:  

## to make and run:  
make test  
2017-01-11T01:08:57 - flwdREST INFO: Starting flwdREST  
2017-01-11T01:08:57 - flwdREST DEBUG: Start framework on port 4437  
  
## Calling the REST service:
While the service is running, use a REST client to send a POST to:  
http://192.168.1.197:4437/flwd/test  
  
When you do, the console on the server will say:  
    Set this word on the FLWD: TEST  

Press <enter> to end the service  
2017-01-11T01:08:58 - flwdREST DEBUG: End framework  
  
# C program that calls python from .py file  
## based on this sample:  
https://docs.python.org/2/extending/embedding.html  

## to build:  
g++ $(python2.7-config --includes --libs) call_py2.c -o call_py2 -lpython2.7  

export PYTHONPATH=.

## to run  
./call_py2 word flwd Woof  

"Should display Woof on hardware."  
