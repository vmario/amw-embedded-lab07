---
title: "Instrukcja laboratorium systemów wbudowanych"
subtitle: "Ćwiczenie 7: Dostęp do pamięci EEPROM mikrokontrolera"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: yes
titlepage-logo: "logo.jpg"
colorlinks: yes
header-includes: |
  \usepackage{awesomebox}
  \usepackage{gensymb}
...

> People think that computer science is the art of geniuses but the actual reality is the opposite, just many people doing things that build on eachother, like a wall of mini stones.
>
> — _Donald Knuth_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* działaniem wbudowanej w mikrokontroler pamięci EEPROM.

# Uruchomienie programu wyjściowego

1. Umieść zworki na pinach `RS`, `E` i `D4`…`D7` złącza `J10` (na lewo od buzzera).
1. Zworkę `J15` (nad buzzerem) ustaw w pozycji `RW->GND`.
1. Umieść wyświetlacz w złączu `DIS1`.
1. Podłącz pin `1WIRE` pod wyświetlaczem siedmiosegmentowym LED do pinu `PD0` mikrokontrolera.
1. Podłącz pin `ENC0 B` pod wyświetlaczem siedmiosegmentowym LED do pinu `PD1` mikrokontrolera.
1. Podłącz pin `ENC0 A` pod wyświetlaczem siedmiosegmentowym LED do pinu `PD2` mikrokontrolera.
1. Podłącz diodę `LED1` do pinu `PD3` mikrokontrolera.
1. Podłącz pin `ENC0 SW` pod wyświetlaczem siedmiosegmentowym LED do pinu `PD4` mikrokontrolera.
1. Po włączeniu zasilania wyświetlacz pokaże bieżącą temperaturę `Tcurrent` oraz temperaturę zadaną `Ttarget`. Dioda `LED1` będzie świecić.

# Zadanie podstawowe

## Wymagania funkcjonalne

Celem zadania podstawowego jest dodanie do termostatu nieulotnej pamięci temperatury zadanej.

1. Po wyjściu z edycji temperatury zadanej ustawiona wartość zapisywana jest w pamięci EEPROM mikrokontrolera.
1. Po zresetowaniu mikrokontrolera wczytywana jest zapamiętana temperatura.

## Modyfikacja programu

# Zadanie rozszerzone

## Wymagania funkcjonalne

Celem zadania rozszerzonego jest dodanie do termostatu regulowanej histerezy.

## Konfiguracja sprzętowa

## Modyfikacja programu

