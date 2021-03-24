# farma

Console game made while learning objective programming paradigm as a 1st year student.

It has a lots of flaws which I decided to fix after Msc graduation and ~3 years of professional experience in Java. And
it's in Polish! ¯\\_(ツ)_/¯

**The game is a farm simulator. One can breed pigs, buy and then upgrade a guard dog to protect the business.**

## Sample gameplay

```cpp
Witaj w grze Farma!
>> Podaj imie: Hanuszka

*** TURA 1 ***

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 0

ZASOBY
Pieniadze: $30
Karma: 0

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Kupic pieska (-$2).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
1
>> Ile chcesz kupic swinek? 2
Zakupiono 2 swinki.

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 2

ZASOBY
Pieniadze: $10
Karma: 0

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Kupic pieska (-$2).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
2

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 2

PIES AZOR
Level: 1
Sila ataku: 4
Glod: 2
Wartosc: 2

ZASOBY
Pieniadze: $8
Karma: 0

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Ulepszyc pieska (-$4).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
4
>> Ile chcesz kupic karmy? 4

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 2

PIES AZOR
Level: 1
Sila ataku: 4
Glod: 2
Wartosc: 2

ZASOBY
Pieniadze: $4
Karma: 4

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Ulepszyc pieska (-$4).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
5
>> Czy koniec tury?[t/n] t
Urodzono 1 swinke.
Zostales zaatakowany przez wilka!
Azor pokonal wilka!
Mama wysyla przelew na $10.

*** TURA 2 ***

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 3

PIES AZOR
Level: 1
Sila ataku: 4
Glod: 2
Wartosc: 2

ZASOBY
Pieniadze: $14
Karma: 2

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Ulepszyc pieska (-$4).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
1
>> Ile chcesz kupic swinek? 1
Zakupiono 1 swinke.

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 4

PIES AZOR
Level: 1
Sila ataku: 4
Glod: 2
Wartosc: 2

ZASOBY
Pieniadze: $4
Karma: 2

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Ulepszyc pieska (-$4).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
2

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 4

PIES AZOR
Level: 2
Sila ataku: 5
Glod: 3
Wartosc: 4

ZASOBY
Pieniadze: $0
Karma: 2

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Ulepszyc pieska (-$6).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
5
>> Czy koniec tury?[t/n] t
Urodzono 2 swinki.
Zostales zaatakowany przez wilka!
Straciles 6 swinek.
Straciles Azora. [*]
Mama wysyla przelew na $10.

*** TURA 3 ***

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 0

ZASOBY
Pieniadze: $10
Karma: 2

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Kupic pieska (-$2).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
1
>> Ile chcesz kupic swinek? 1
Zakupiono 1 swinke.

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 1

ZASOBY
Pieniadze: $0
Karma: 2

Co chcesz zrobić?
1. Kupic swinki (-$10).
2. Kupic pieska (-$2).
3. Sprzedac swinki (+$10).
4. Kupic karme (-$1).
5. Zakonczyc ture.
5
>> Czy koniec tury?[t/n] t

OTO TWOJA FARMA:

ZWIERZETA NA FARMIE
Liczba swinek: 1

ZASOBY
Pieniadze: $0
Karma: 2

Koniec gry.
Wygrana!
Zagrano 3 tur.
Hanuszka konczy z wynikiem 10 punktow.

         ___
         ',_`""\        .---,
            \   :-""``/`    |
             `;'     //`\   /
             /   __     |   ('.
            |_ ./O)\     \  `) \
           _/-.    `      `"`  |`-.
       .-=; `                  /   `-.
      /o o \   ,_,           .        '.
      L._._;_.-'           .            `'-.
        `'-.`             '                 `'-.
            `.         '                        `-._
              '-._. -'                              '.
                 \                                    `\
                  |                                     \
                  |    |                                 ;   _.
                  \    |           |                     |-.((
                   ;.  \           /    /                |-.`\)
                   | '. ;         /    |                 |(_) )
                   |   \ \       /`    |                 ;'--'
                    \   '.\    /`      |                /
                     |   /`|  ;        \               /
                     |  |  |  |-._      '.           .'
                     /  |  |  |__.`'---"_;'-.     .-'
                    //__/  /  |    .-'``     _.-'`
                          //__/   //___.--''`

```
