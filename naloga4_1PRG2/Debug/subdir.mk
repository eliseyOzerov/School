################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Calendar.cpp \
../Date.cpp \
../DateTime.cpp \
../Event.cpp \
../MeetingEvent.cpp \
../Time.cpp \
../naloga4_1PRG2.cpp 

OBJS += \
./Calendar.o \
./Date.o \
./DateTime.o \
./Event.o \
./MeetingEvent.o \
./Time.o \
./naloga4_1PRG2.o 

CPP_DEPS += \
./Calendar.d \
./Date.d \
./DateTime.d \
./Event.d \
./MeetingEvent.d \
./Time.d \
./naloga4_1PRG2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


