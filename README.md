make test

send a POST to:
http://192.168.1.197:4437/flwd/test

When you do, the console on the server will say:
    Set this word on the FLWD: TEST

-----
g++ $(python-config --includes --libs) call_py.c -lpython2.7 -o call_py
./call_py
output will be:
   hello

g++ $(python-config --includes --libs) call_ext_py.c -lpython2.7 -o call_ext_py


