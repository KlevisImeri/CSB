clear
rm ./a.exe 
g++ ./src/main.cpp -I./include 
#g++ ./src/main.cpp -I./include -L./lib -lraylib -lopengl32 -lgdi32 -lwinmm 
./a.exe  | head -n 10