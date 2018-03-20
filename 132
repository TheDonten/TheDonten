## Laboratory work II

Данная лабораторная работа посвещена изучению утилит для разработки проектов

## Tasks

- [x] 1. Ознакомиться со ссылками учебного материала
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Составить отчет и отправить ссылку личным сообщением в **Slack**
 
## Tutorial

```bash
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GIST_TOKEN=<сохраненный_токен>
$ alias edit=<nano|vi|vim|subl>
```

```ShellSession
$ mkdir -p ${GITHUB_USERNAME}/workspace
$ cd ${GITHUB_USERNAME}/workspace
$ pwd
$ cd ..
$ pwd
```

```ShellSession
$ mkdir -p workspace/tasks/
$ mkdir -p workspace/projects/
$ mkdir -p workspace/reports/
$ cd workspace
```

```ShellSession
# Debian
$ wget https://nodejs.org/dist/v6.11.5/node-v6.11.5-linux-x64.tar.xz
$ tar -xf node-v6.11.5-linux-x64.tar.xz
$ rm -rf node-v6.11.5-linux-x64.tar.xz
$ mv node-v6.11.5-linux-x64 node
```

```ShellSession
$ ls node/bin 
$ echo ${PATH}
$ export PATH=${PATH}:`pwd`/node/bin
$ echo ${PATH}
$ mkdir scripts
$ cat > scripts/activate<<EOF
export PATH=\${PATH}:`pwd`/node/bin
EOF
$ source scripts/activate
```

```ShellSession
$ npm install -g gistup
$ ls node/bin
```

```ShellSession
$ cat > ~/.gistup.json <<EOF
{
  "token": "${GIST_TOKEN}"
}
EOF
```

## Report

```ShellSession
$ export LAB_NUMBER=02
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}" # enter: yes↵
```

## Links

### Unix commands

- [ar](https://en.wikipedia.org/wiki/Ar_(Unix)) - стандартная утилита Unix, архиватор, не использующий сжатия данных.
- [cat](https://en.wikipedia.org/wiki/Cat_(Unix)) -стандартная утилита Unix, записывающая файлы последовательно, записывающая их в один поток.
- [cd](https://en.wikipedia.org/wiki/Cd_(command)) -команда командной строки для изменения текущего рабочего каталога.
- [cp](https://en.wikipedia.org/wiki/Cp_(Unix)) - предназначенная для копирования файлов из одного в другие каталоги.
- [cut](https://en.wikipedia.org/wiki/Cut_(Unix)) - команда выборки отдельных полей из строк файла.
- [echo](https://en.wikipedia.org/wiki/Echo_(command)) - используется для вывода текста на экран или файл.
- [env](https://en.wikipedia.org/wiki/Env_(shell)) - используется для печати списка переменных среды или при запуске другой утилиты в изменненой среде, без изменения существующей среды.
- [ex](https://en.wikipedia.org/wiki/Ex_(editor)) - Текстовый редактор на Unix.
- [file](https://en.wikipedia.org/wiki/File_(command)) - предназначена для распознования типа данных, находящихся в компутере.
- [find](https://en.wikipedia.org/wiki/Find) - Поисковик.
- [ls](https://en.wikipedia.org/wiki/Ls) - утилита Unix, которая печатает в стандартный вывод содержимое каталогов.
- [man](https://en.wikipedia.org/wiki/Man_page) -  предназначенная для форматирования и вывода справочных страниц.
- [mkdir](https://en.wikipedia.org/wiki/Mkdir) - используется для создания каталога.
- [mv](https://en.wikipedia.org/wiki/Mv) - используется для перемещения или переименования файлов.
- [nm](https://en.wikipedia.org/wiki/Nm_(Unix)) -  печатающая информацию о бинарных файлах (объектных файлах, библиотеках)
- [ps](https://en.wikipedia.org/wiki/Ps_(Unix)) - выводящая отчёт о работающих процессах.
- [pwd](https://en.wikipedia.org/wiki/Pwd) - консольная утилита в UNIX-подобных системах, которая выводит полный путь от корневого каталога к текущему рабочему .
- [rm](https://en.wikipedia.org/wiki/Rm_(Unix)) - позволяет удалять файлы и обьекты.
- [sed](https://en.wikipedia.org/wiki/Sed) -  потоковый текстовый редактор (а также язык программирования).
- [touch](https://en.wikipedia.org/wiki/Touch_(Unix)) - команда Unix, предназначенная для установки времени последнего изменения файла или доступа в текущее время.

### Package Managers

- [apt](http://help.ubuntu.ru/wiki/apt) | [dnf](https://en.wikipedia.org/wiki/DNF_(software)) | [yum](https://fedoraproject.org/wiki/Yum/ru) - набор утилит для управления программными пакетами в операционных системах основанных на Debian.
- [brew](https://brew.sh) | [linuxbrew](http://linuxbrew.sh) - менеджер пакетов macOS для Linux.
- [npm](https://docs.npmjs.com) - менеджер пакетов, входящий в состав Node.js

### Software

- [curl](https://www.gitbook.com/book/bagder/everything-curl/details) - , позволяющая взаимодействовать с множеством различных серверов по множеству различных протоколов с синтаксисом URL.
- [wget](https://www.gnu.org/software/wget/manual/wget.pdf) - свободная  консольная программа для загрузки файлов по сети.
- [clang](https://clang.llvm.org) - является фронтендом для языков программирования C, C++, Objective-C, Objective-C++ (англ.) и OpenCL С.
- [g++](https://gcc.gnu.org/onlinedocs/gcc-4.0.2/gcc/G_002b_002b-and-GCC.html) - компилятор.
- [make](https://en.wikipedia.org/wiki/Make_(software)) - омпиляция исходного кода в объектные файлы и последующая компоновка в исполняемые файлы или библиотеки.
- [open](https://developer.apple.com/legacy/library/documentation/Darwin/Reference/ManPages/man1/open.1.html) - позволяет открывать файлы.
- [openssl](https://www.openssl.org) - Криптография и набор инструментов SSL / TLS.
- [nano](https://www.nano-editor.org)- консольный текстовый редактор для UNIX.
- [tree](https://linux.die.net/man/1/tree) -  программа для рекурсивного каталога.
- [vim](http://www.vim.org) - текстовый редактор.

```
Copyright (c) 2017 Братья Вершинины
```
