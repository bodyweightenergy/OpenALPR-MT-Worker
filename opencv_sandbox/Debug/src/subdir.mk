################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Buffer.cpp \
../src/Consumer.cpp \
../src/DisplayImage.cpp \
../src/Job.cpp \
../src/Producer.cpp 

OBJS += \
./src/Buffer.o \
./src/Consumer.o \
./src/DisplayImage.o \
./src/Job.o \
./src/Producer.o 

CPP_DEPS += \
./src/Buffer.d \
./src/Consumer.d \
./src/DisplayImage.d \
./src/Job.d \
./src/Producer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/include -I/usr/include -I/usr/local/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


