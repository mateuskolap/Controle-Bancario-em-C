@echo off
setlocal enabledelayedexpansion

REM Remove o diretório bin e cria um novo
if exist bin rmdir /s /q bin
mkdir bin

REM Encontra todos os arquivos .c no diretório src e seus subdiretórios
set "SRC_FILES="
for /r src %%f in (*.c) do (
    set "SRC_FILES=!SRC_FILES! %%f"
)

REM Compila o código-fonte
gcc -Wall -Wextra -Wpedantic !SRC_FILES! -o bin\main.exe

REM Verifica o sistema operacional e executa o programa
if "%OS%" == "Windows_NT" (
    echo Executando no Windows...
    bin\main.exe
    pause
) else (
    echo Sistema operacional não suportado.
    exit /b 1
)