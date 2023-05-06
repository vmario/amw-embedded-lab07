/**
 * @file
 * @author Mariusz Chilmon <mariusz.chilmon@ctm.gdynia.pl>
 * @date 2023
 * 
 * Pętla główna.
 */

#include "lcd.hpp"
#include "encoder.hpp"
#include "timer.hpp"
#include "thermometer.hpp"
#include "thermostat.hpp"

#include <avr/interrupt.h>

#include <stdlib.h>
#include <stdio.h>

/**
 * Wyświetla komunikat powitalny.
 */
static void lcdSplash(const Lcd& lcd)
{
	lcd.clear();
	lcd.write("Initializing...");
}

/**
 * Wyświetla temperaturę.
 * 
 * @param lcd Sterownik LCD.
 */
static void printTemperature(const Lcd& lcd)
{
	char buffer[17];
	snprintf(buffer, sizeof(buffer), "Tcurrent =%6.2f", Thermometer{}.temperature());
	lcd.write(buffer);
}

/**
 * Wyświetla numer seryjny termometru.
 * 
 * @param lcd Sterownik LCD.
 * @param thermostat Sterownik termostatu.
 */
static void printTarget(const Lcd& lcd, const Thermostat& thermostat, char cursor)
{
	char buffer[17];
	snprintf(buffer, sizeof(buffer), "Ttarget  %c%6.2f", cursor, thermostat.target());
	lcd.write(buffer);
}

/**
 * Wyświetla pomiar temperatury.
 * 
 * @param lcd Sterownik LCD.
 * @param thermostat Sterownik termostatu.
 */
static void lcdRefresh(const Lcd& lcd, const Thermostat& thermostat, char cursor)
{
	if (!Thermometer{}.reset()) {
		lcd.clear();
		lcd.write("1-Wire Error :( ");
		return;
	}

	lcd.goTo(0, 0);
	printTemperature(lcd);
	lcd.goTo(1, 0);
	printTarget(lcd, thermostat, cursor);
}

/**
 * Obsługa wyświetlacza, termometru i termostatu obsługiwana cyklicznie
 * w każdym ticku systemowym.
 *
 * @param lcd Sterownik LCD.
 * @param thermostat Sterownik termostatu.
 */
void onSystemTick(const Lcd& lcd, Thermostat& thermostat)
{
	static bool lastSwitch = false;
	static char cursor = '=';

	thermostat.onTemperature(Thermometer{}.temperature());
	if (lastSwitch != encoder.isSwitchPressed()) {
		lastSwitch = encoder.isSwitchPressed();
		if (lastSwitch) {
			if (cursor == '=') {
				cursor = '>';
			} else {
				cursor = '=';
			}
		}
	}
	if (cursor == '>') {
		thermostat.target(thermostat.target() + 0.1 * encoder.pop());
	} else {
		encoder.pop();
	}
	lcdRefresh(lcd, thermostat, cursor);
}

/**
 * Funkcja główna.
 */
int main()
{
	const SystemTick tick;
	const Lcd lcd;
	Thermostat thermostat;

	lcd.init();
	encoder.init();
	tick.init();
	lcdSplash(lcd);
	sei();

	while (true) {
		if (tick.pop()) {
			onSystemTick(lcd, thermostat);
		}
	}

	return EXIT_SUCCESS;
}