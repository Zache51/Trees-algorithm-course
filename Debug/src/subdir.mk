################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BinaryTree.cpp \
../src/TreeNode.cpp \
../src/main.cpp 

OBJS += \
./src/BinaryTree.o \
./src/TreeNode.o \
./src/main.o 

CPP_DEPS += \
./src/BinaryTree.d \
./src/TreeNode.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -DSFML_DYNAMIC -I/usr/include/SFML -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


