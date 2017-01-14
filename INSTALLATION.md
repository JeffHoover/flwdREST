## compile call_py2, which calls python from C  
   ./compile.sh  

## run call_py2 with word.py and an example word that could come in on a route.  
   ./run.sh  

## determine ip address of pi  
   fconfig | grep "inet addr:192"  

## Build the REST server  
   make  
## run flwd REST server, noting the port number  
   ./flwdREST  

## Test the rest server  
In a REST client, post to the ip address and port number, this route:  
   flwd/word  
For example:  
   http://192.168.1.197:4437/flwd/KitTTy  
Server should output:  
   Set this word on the FLWD: KITT  

## End server with <enter> in server window  

## Test the hardware:  
   export PYTHONPATH=. && ./call_py2 alphanum4_test flwd MOOM  
OR  
   ./run.sh  

## Clear the hardware:  
   export PYTHONPATH=. && ./call_py2 alphanum4_test clear  
OR  
   ./clear.sh  



