base  = "#!/bin/bash\n\n"

files = ["Logger/logger.cpp",
         "Timer/timer.cpp",
         "Input/keyboard.cpp",
         "Input/mouse.cpp",
         "Drawer/drawer.cpp"]

def compile_file(filename):
    return "g++ %s -c -Wall &&\n" % filename

for f in files:
    base += compile_file(f)
base += compile_file("main.cpp")
base += "g++ main.o "
for f in files:
    cpp = f.split("/")[-1]
    o = cpp.split(".cpp")[0] + ".o"
    base += o
    base += " "

base += "-o main -lSDL -lSDL_image -lSDL_ttf -Wall"

print base
