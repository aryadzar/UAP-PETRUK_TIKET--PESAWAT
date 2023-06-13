# UAP-PETRUK_TIKET--PESAWAT
Pemesanan tiket pesawat dengan menggunakan c++ 

Anggota : 
1. Muhammad Ferdiansyah (2217051126)
2. Muhammad Arif Rizki Fauhan (2217051090)
3. Muhammad Arya Dzaky Arenanto (2217051007)

Untuk menjalankan program ini pastikan menginstall libary SFML yang tertera pada link ini 

https://www.sfml-dev.org/download.php


File ini mengandung isi sebagai berikut :

1. Procedures and Functions
2. Arrays and Pointers
3. C++ Class
4. Lists and Vectors
5. Stacks and Queues
6. Divide and Conquer Algorithm

Ketika ingin menjalankan program ini pastikan ada file atten.wav 
dan end.wav jika ingin ada suara yang dikeluarkan pada program tersebut

Project ini kami harapkan bisa menginspirasi untuk project kedepannya 

pada macos / linux jalankan c++ denngan menggunakan g++ seperti berikut 
```
#!/bin/bash

g++ -std=c++11 utaman.cpp -o p -lsfml-audio

if [ $? -ne 0 ]; then
  echo "Kesalahan saat kompilasi file C++"
  exit 1
fi

./p

```
Atau bisa dilihat pada file `run.sh`

Untuk Windows, jalan file c++ berikut dengan menggunakan g++ sebagai berikut
```
@echo off

g++ utaman.cpp -o coba -lsfml-audio-2

if %ERRORLEVEL% neq 0 (
    echo Kesalahan pada program
    exit /b 1
)

.\coba.exe

```

Atau bisa dilihat pada file `run.bat`




Terima kasih Semoga program ini dapat dipahami oleh semuanya 
