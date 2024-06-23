# *****************************************************
# Julio Vega
# Example of Makefile
# *****************************************************
# NOTES: it uses '>' as prefix of my recipes (.RECIPEPREFIX is set in line 11)
# since all actions of every Makefile's rule are identified by tabs and I do not
# use tabs in my file editor. Otherwise, I will get the 'missing separator' error.
#
# To check whether a tab character is used, run: cat -e -t -v Makefile
# It shows the presence of tabs (-t) with ^I and line endings (-e) with $
# *****************************************************

CC = g++
CFLAGS = -Wall -g -Wshadow
.RECIPEPREFIX = >

main: main.o Employee.o Admin.o Supervisor.o Worker.o UserDB.o Sensor.o Temp.o Humidity.o AirQuality.o LightQuality.o Magnetic.o Camera.o RGB.o Termic.o SensorDB.o Alarm.o Login.o DashBoard.o
>$(CC) $(CFLAGS) -o main main.o Employee.o Admin.o Supervisor.o Worker.o UserDB.o Sensor.o Temp.o Humidity.o AirQuality.o LightQuality.o Magnetic.o Camera.o RGB.o Termic.o SensorDB.o Alarm.o Login.o DashBoard.o

main.o: main.cpp Employee.h Admin.h Supervisor.h Worker.h UserDB.h Sensor.h Temp.h Humidity.h AirQuality.h LightQuality.h Magnetic.h Camera.h RGB.h Termic.h SensorDB.h Alarm.h Login.h DashBoard.h
>$(CC) $(CFLAGS) -c main.cpp Employee.cpp UserDB.cpp Sensor.cpp Camera.cpp SensorDB.cpp Alarm.cpp Login.cpp DashBoard.cpp
 
Employee.o: Employee.h

Admin.o: Admin.h

Supervisor.o: Supervisor.h

Worker.o: Worker.h

UserDB.o: UserDB.h

Sensor.o: Sensor.h

Temp.o: Temp.h

Humidity.o: Humidity.h

AirQuality.o: AirQuality.h

LightQuality.o: LightQuality.h

Magnetic.o: Magnetic.h

Camera.o: Camera.h

RGB.o: RGB.h

Termic.o: Termic.h

SensorDB.o : SensorDB.h

Alarm.o : Alarm.h

Login.o : Login.h

DashBoard.o : DashBoard.h

clean:
>rm *.o main
