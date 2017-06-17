Sa se definească o clasă generică pentru fracţii cu numărător şi denominator de un tip T neprecizat (parametru),
în care operatorii =, ==, operatorii aritmetici, +, - (unar si binar), * şi / să fie supraîncărcaţi
pentru operaţiile obişnuite cu fracţii,
iar operatorul (tip) de conversie a tipurilor să fie supraîncărcat pentru a efectua conversia unui obiect de tipul T  la o fracţie
care are ca denominator "unitatea" din tipul T (element neutru la *), care poate fi elementul construit de un anume constructor al clasei T,
având argument de tip int, care să dea sens declaraţiei cu iniţializare T a=1
(ca şi declaraţiei cu iniţializare T a=0, din care va rezulta elementul "zero" din tipul T, neutru la +).

Se vor da exemple de creare şi utilizare de obiecte pentru diferite tipuri ale numărătorului şi numitorului :
int, întregi Gauss, adică numere complexe cu părţile reală şi imaginară de tip int
(după definirea acestora ca o clasă separată), etc.



 Warnings solved
 --------
- explicit: Single argument constructors must be marked explicit to avoid unintentional implicit conversions
- =default: Use '= default' to define a trivial destructor
- constructors: Class 'Complex' defines a destructor, a copy constructor, a copy assignment constructor but does not define a move constructor and a move assignment constructor


 Compiling single file...
 --------
 - Filename: E:\temur\Desktop\poo-proiect-fractii.cpp
 - Compiler Name: TDM-GCC 4.9.2 64-bit Release

 Processing C++ source file...
 --------
 - C++ Compiler: C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe
 - Command: g++.exe "E:\temur\Desktop\poo-proiect-fractii.cpp" -o "E:\temur\Desktop\poo-proiect-fractii.exe"  -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\include" -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include" -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.9.2\include" -I"C:\Program Files (x86)\Dev-Cpp\MinGW64\lib\gcc\x86_64-w64-mingw32\4.9.2\include\c++" -L"C:\Program Files (x86)\Dev-Cpp\MinGW64\lib" -L"C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib" -static-libgcc
 E:\temur\Desktop\poo-proiect-fractii.cpp:42:16: warning: defaulted and deleted functions only available with -std=c++11 or -std=gnu++11
      ~Fractie()=default;
                 ^
 E:\temur\Desktop\poo-proiect-fractii.cpp: In constructor 'Fractie<T>::Fractie(T, T)':
 E:\temur\Desktop\poo-proiect-fractii.cpp:30:40: warning: extended initializer lists only available with -std=c++11 or -std=gnu++11
              throw std::invalid_argument{"Numitor invalid (0) !"};
                                         ^
 E:\temur\Desktop\poo-proiect-fractii.cpp: At global scope:
 E:\temur\Desktop\poo-proiect-fractii.cpp:122:16: warning: defaulted and deleted functions only available with -std=c++11 or -std=gnu++11
      ~Complex()=default;
                 ^
 E:\temur\Desktop\poo-proiect-fractii.cpp: In member function 'Complex Complex::operator/(float)':
 E:\temur\Desktop\poo-proiect-fractii.cpp:158:40: warning: extended initializer lists only available with -std=c++11 or -std=gnu++11
              throw std::invalid_argument{"Numitor invalid (0) !"};
                                         ^
 E:\temur\Desktop\poo-proiect-fractii.cpp: In member function 'Complex Complex::operator/(const Complex&)':
 E:\temur\Desktop\poo-proiect-fractii.cpp:168:40: warning: extended initializer lists only available with -std=c++11 or -std=gnu++11
              throw std::invalid_argument{"modulul este 0!"};
                                         ^

 Compilation results...
 --------
 - Errors: 0
 - Warnings: 5
 - Output Filename: E:\temur\Desktop\poo-proiect-fractii.exe
 - Output Size: 1,85542297363281 MiB
 - Compilation Time: 0,94s
