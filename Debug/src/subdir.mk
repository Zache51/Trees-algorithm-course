################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BinaryTree.cpp \
../src/BinaryTreeNode.cpp \
../src/TernaryTree.cpp \
../src/TernaryTreeNode.cpp \
../src/TreeNode.cpp \
../src/main.cpp 

OBJS += \
./src/BinaryTree.o \
./src/BinaryTreeNode.o \
./src/TernaryTree.o \
./src/TernaryTreeNode.o \
./src/TreeNode.o \
./src/main.o 

CPP_DEPS += \
./src/BinaryTree.d \
./src/BinaryTreeNode.d \
./src/TernaryTree.d \
./src/TernaryTreeNode.d \
./src/TreeNode.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


