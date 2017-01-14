## Set python path  
export PYTHONPATH=.  

## compile call_py2, which calls python from C  
   g++ $(python2.7-config --includes --libs) call_py2.c -o call_py2 -lpython2.7  
OR  
   ./compile.sh  

## Build the REST server  
   make  

## determine ip address of pi  
   ifconfig | grep "inet addr:192"  

## run the REST server, noting the port number  
   ./flwdREST  

## Call the REST server to display word on hardware  
In a REST client, post to the ip address and port number, this route:  
   flwd/word  
For example:  
   http://192.168.1.197:4437/flwd/KitTTy  

## End server   
'enter' in server window  

