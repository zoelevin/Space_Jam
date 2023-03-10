#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/AD.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/BOARD.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_CheckEvents.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Framework.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_KeyboardInput.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_PostList.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Queue.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_TattleTale.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Timers.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/IO_Ports.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/LED.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ToneGeneration.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/Wheels.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/pwm.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/serial.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/timers.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/EventChecker.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/HSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Service.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Stepper.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubBeaconHSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubReloadHSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubWallFollowHSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/templates/ES_Main.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/RC_Servo.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/779059726/AD.o ${OBJECTDIR}/_ext/779059726/BOARD.o ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o ${OBJECTDIR}/_ext/779059726/ES_Framework.o ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o ${OBJECTDIR}/_ext/779059726/ES_PostList.o ${OBJECTDIR}/_ext/779059726/ES_Queue.o ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o ${OBJECTDIR}/_ext/779059726/ES_Timers.o ${OBJECTDIR}/_ext/779059726/IO_Ports.o ${OBJECTDIR}/_ext/779059726/LED.o ${OBJECTDIR}/_ext/779059726/ToneGeneration.o ${OBJECTDIR}/_ext/779059726/Wheels.o ${OBJECTDIR}/_ext/779059726/pwm.o ${OBJECTDIR}/_ext/779059726/serial.o ${OBJECTDIR}/_ext/779059726/timers.o ${OBJECTDIR}/_ext/1736485445/EventChecker.o ${OBJECTDIR}/_ext/1736485445/HSM.o ${OBJECTDIR}/_ext/1736485445/Service.o ${OBJECTDIR}/_ext/1736485445/Stepper.o ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o ${OBJECTDIR}/_ext/164314937/ES_Main.o ${OBJECTDIR}/_ext/1736485445/RC_Servo.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/779059726/AD.o.d ${OBJECTDIR}/_ext/779059726/BOARD.o.d ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o.d ${OBJECTDIR}/_ext/779059726/ES_Framework.o.d ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o.d ${OBJECTDIR}/_ext/779059726/ES_PostList.o.d ${OBJECTDIR}/_ext/779059726/ES_Queue.o.d ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o.d ${OBJECTDIR}/_ext/779059726/ES_Timers.o.d ${OBJECTDIR}/_ext/779059726/IO_Ports.o.d ${OBJECTDIR}/_ext/779059726/LED.o.d ${OBJECTDIR}/_ext/779059726/ToneGeneration.o.d ${OBJECTDIR}/_ext/779059726/Wheels.o.d ${OBJECTDIR}/_ext/779059726/pwm.o.d ${OBJECTDIR}/_ext/779059726/serial.o.d ${OBJECTDIR}/_ext/779059726/timers.o.d ${OBJECTDIR}/_ext/1736485445/EventChecker.o.d ${OBJECTDIR}/_ext/1736485445/HSM.o.d ${OBJECTDIR}/_ext/1736485445/Service.o.d ${OBJECTDIR}/_ext/1736485445/Stepper.o.d ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o.d ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o.d ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o.d ${OBJECTDIR}/_ext/164314937/ES_Main.o.d ${OBJECTDIR}/_ext/1736485445/RC_Servo.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/779059726/AD.o ${OBJECTDIR}/_ext/779059726/BOARD.o ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o ${OBJECTDIR}/_ext/779059726/ES_Framework.o ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o ${OBJECTDIR}/_ext/779059726/ES_PostList.o ${OBJECTDIR}/_ext/779059726/ES_Queue.o ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o ${OBJECTDIR}/_ext/779059726/ES_Timers.o ${OBJECTDIR}/_ext/779059726/IO_Ports.o ${OBJECTDIR}/_ext/779059726/LED.o ${OBJECTDIR}/_ext/779059726/ToneGeneration.o ${OBJECTDIR}/_ext/779059726/Wheels.o ${OBJECTDIR}/_ext/779059726/pwm.o ${OBJECTDIR}/_ext/779059726/serial.o ${OBJECTDIR}/_ext/779059726/timers.o ${OBJECTDIR}/_ext/1736485445/EventChecker.o ${OBJECTDIR}/_ext/1736485445/HSM.o ${OBJECTDIR}/_ext/1736485445/Service.o ${OBJECTDIR}/_ext/1736485445/Stepper.o ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o ${OBJECTDIR}/_ext/164314937/ES_Main.o ${OBJECTDIR}/_ext/1736485445/RC_Servo.o

# Source Files
SOURCEFILES=C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/AD.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/BOARD.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_CheckEvents.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Framework.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_KeyboardInput.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_PostList.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Queue.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_TattleTale.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Timers.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/IO_Ports.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/LED.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ToneGeneration.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/Wheels.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/pwm.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/serial.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/timers.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/EventChecker.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/HSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Service.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Stepper.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubBeaconHSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubReloadHSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubWallFollowHSM.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/templates/ES_Main.c C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/RC_Servo.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=,--script="C:\Users\zoeal\OneDrive\Documents\ECE118_SpaceJam\ECE118\bootloader320.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/779059726/AD.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/AD.c  .generated_files/flags/default/bbd4720e4aa4a812c214aeb30efb8efb7a2ce96 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/AD.o.d" -o ${OBJECTDIR}/_ext/779059726/AD.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/BOARD.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/BOARD.c  .generated_files/flags/default/c80d75fda319df277e4399207a4ac3f8d6c8d730 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/BOARD.o.d" -o ${OBJECTDIR}/_ext/779059726/BOARD.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_CheckEvents.c  .generated_files/flags/default/c5981aab07d7e69cdd44a39a80a7d127abfbd767 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_Framework.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Framework.c  .generated_files/flags/default/7a9106ac6bddeebd15efcfaeec1d0f0906dc2cd9 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_Framework.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_KeyboardInput.c  .generated_files/flags/default/359323a71910950b5a948fc600015ca9c42a7c92 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_PostList.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_PostList.c  .generated_files/flags/default/60d6e1f70007a5e7c04ba8b8d8ab44a77385a909 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_PostList.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_Queue.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Queue.c  .generated_files/flags/default/52b3b85355159fb961a3889173fc2cffa1b94662 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_Queue.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_TattleTale.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_TattleTale.c  .generated_files/flags/default/d67da9c772b949b914f17e5b0602a1a3519c6429 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_Timers.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Timers.c  .generated_files/flags/default/4954a31a5a6c95435d2aa61effd2a3e89c703350 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_Timers.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/IO_Ports.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/IO_Ports.c  .generated_files/flags/default/2ff3fca95aba111ab33b015b4d9d01112731d3dd .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/779059726/IO_Ports.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/LED.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/LED.c  .generated_files/flags/default/23356b5081c837abf00fa24f2baa697606522dd1 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/LED.o.d" -o ${OBJECTDIR}/_ext/779059726/LED.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ToneGeneration.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ToneGeneration.c  .generated_files/flags/default/853e16dde84bb6a8c15cecb863075e798bfeff76 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ToneGeneration.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ToneGeneration.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ToneGeneration.o.d" -o ${OBJECTDIR}/_ext/779059726/ToneGeneration.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ToneGeneration.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/Wheels.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/Wheels.c  .generated_files/flags/default/81839c224c141447149a4105758b9c15268a0780 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/Wheels.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/Wheels.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/Wheels.o.d" -o ${OBJECTDIR}/_ext/779059726/Wheels.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/Wheels.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/pwm.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/pwm.c  .generated_files/flags/default/a532c812ce119478b2e31de329aa5e3558b44ec6 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/pwm.o.d" -o ${OBJECTDIR}/_ext/779059726/pwm.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/serial.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/serial.c  .generated_files/flags/default/3640387855b40d35cb73a53e96a4b11321e740f7 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/serial.o.d" -o ${OBJECTDIR}/_ext/779059726/serial.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/timers.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/timers.c  .generated_files/flags/default/db5370234fb7c4f2f1cf494133f7747acc859fe5 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/timers.o.d" -o ${OBJECTDIR}/_ext/779059726/timers.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/EventChecker.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/EventChecker.c  .generated_files/flags/default/84c92ccd8279ea4b0a3c4fde1d47ab1347600b75 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/EventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/EventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/EventChecker.o.d" -o ${OBJECTDIR}/_ext/1736485445/EventChecker.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/EventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/HSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/HSM.c  .generated_files/flags/default/9dbad47c8ee9269198f7f3e3406675c9f7041093 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/HSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/HSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/HSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/HSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/HSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/Service.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Service.c  .generated_files/flags/default/d3b7e14e1107e32e6f4ae34e74a789c203c89454 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Service.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/Service.o.d" -o ${OBJECTDIR}/_ext/1736485445/Service.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/Stepper.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Stepper.c  .generated_files/flags/default/67b5259eec35ce9fc990d1c36d5b503332f0f2d5 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Stepper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Stepper.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/Stepper.o.d" -o ${OBJECTDIR}/_ext/1736485445/Stepper.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Stepper.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubBeaconHSM.c  .generated_files/flags/default/5dd8e88bcc11ea06bb5dc215e39630625d5e703e .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubBeaconHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubReloadHSM.c  .generated_files/flags/default/2267c8248c1bb3274cf426ce825a477df2fdb896 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubReloadHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubWallFollowHSM.c  .generated_files/flags/default/950a40225cbd21053133de3a13af4eebaa83b692 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubWallFollowHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/164314937/ES_Main.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/templates/ES_Main.c  .generated_files/flags/default/7f5e1f924d723b003015e872e81054d752b8c355 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/164314937" 
	@${RM} ${OBJECTDIR}/_ext/164314937/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/164314937/ES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/164314937/ES_Main.o.d" -o ${OBJECTDIR}/_ext/164314937/ES_Main.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/templates/ES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/RC_Servo.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/RC_Servo.c  .generated_files/flags/default/602454e9060e044b9eda8a443f0b89691e5d65b8 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/RC_Servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/1736485445/RC_Servo.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/RC_Servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/779059726/AD.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/AD.c  .generated_files/flags/default/b8e11d64fd89172046cba4cc27a856903990f6d7 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/AD.o.d" -o ${OBJECTDIR}/_ext/779059726/AD.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/BOARD.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/BOARD.c  .generated_files/flags/default/9e672388a696553e04416486500771cfc96575fb .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/BOARD.o.d" -o ${OBJECTDIR}/_ext/779059726/BOARD.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_CheckEvents.c  .generated_files/flags/default/49215fc5647fc16b972ecd8ada1cd08b7b6421a .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_CheckEvents.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_Framework.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Framework.c  .generated_files/flags/default/899815cbb1c72eca7138b2adb765db6412dace7e .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_Framework.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_KeyboardInput.c  .generated_files/flags/default/e18b7f316a9008b005f58ddfcd9bc70c3a7a8263 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_KeyboardInput.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_PostList.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_PostList.c  .generated_files/flags/default/e455ef1dadf6b457ef185f9f552b8ac0559958be .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_PostList.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_Queue.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Queue.c  .generated_files/flags/default/31c78868a70999fbc659c0eab166d07a5a27d0fb .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_Queue.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_TattleTale.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_TattleTale.c  .generated_files/flags/default/e26df3b2a560b16fbb8dc64bc76ceda29894242 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_TattleTale.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ES_Timers.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Timers.c  .generated_files/flags/default/a6ba5c012a3840af70cadf45512adc7e8d99b2d .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/779059726/ES_Timers.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/IO_Ports.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/IO_Ports.c  .generated_files/flags/default/4fb412c3b06a3b80fe41ec80d4bb7dcc07de3614 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/779059726/IO_Ports.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/LED.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/LED.c  .generated_files/flags/default/d2fcd6fed10b9034eb61d9970cea734cdc67faf8 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/LED.o.d" -o ${OBJECTDIR}/_ext/779059726/LED.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/ToneGeneration.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ToneGeneration.c  .generated_files/flags/default/74a2278b62eb1f21d3904951c2885088f78fb4ba .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/ToneGeneration.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/ToneGeneration.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/ToneGeneration.o.d" -o ${OBJECTDIR}/_ext/779059726/ToneGeneration.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/ToneGeneration.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/Wheels.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/Wheels.c  .generated_files/flags/default/8a7007a104a0ca1de0b2a22788b3d32f8fabeb7 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/Wheels.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/Wheels.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/Wheels.o.d" -o ${OBJECTDIR}/_ext/779059726/Wheels.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/Wheels.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/pwm.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/pwm.c  .generated_files/flags/default/714d4e4011f7a9da4309bba5362fd5873b4aca12 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/pwm.o.d" -o ${OBJECTDIR}/_ext/779059726/pwm.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/serial.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/serial.c  .generated_files/flags/default/ac4c458ebf85796f221b9ae04e53254a674df5e0 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/serial.o.d" -o ${OBJECTDIR}/_ext/779059726/serial.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/779059726/timers.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/timers.c  .generated_files/flags/default/cac5e55652e6587e202291cbea6f01e5e169b945 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/779059726" 
	@${RM} ${OBJECTDIR}/_ext/779059726/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/779059726/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/779059726/timers.o.d" -o ${OBJECTDIR}/_ext/779059726/timers.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/EventChecker.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/EventChecker.c  .generated_files/flags/default/48ac144f419c67f902e74524a11466ee21902a .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/EventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/EventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/EventChecker.o.d" -o ${OBJECTDIR}/_ext/1736485445/EventChecker.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/EventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/HSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/HSM.c  .generated_files/flags/default/bf9306813568f4cf8e1ad4ca055b85b4bc531296 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/HSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/HSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/HSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/HSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/HSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/Service.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Service.c  .generated_files/flags/default/151cbb5b18596db211d74bd35715ba09a2219693 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Service.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/Service.o.d" -o ${OBJECTDIR}/_ext/1736485445/Service.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/Stepper.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Stepper.c  .generated_files/flags/default/9a88b6c419085f5e896d546217c9e9074766a416 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Stepper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/Stepper.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/Stepper.o.d" -o ${OBJECTDIR}/_ext/1736485445/Stepper.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/Stepper.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubBeaconHSM.c  .generated_files/flags/default/4ed0758ea73ef50f6b10c4d64f30808c613fa9a8 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/SubBeaconHSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubBeaconHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubReloadHSM.c  .generated_files/flags/default/39fbe53d629ae96b5b0628d14b8fbcfd39ba87d2 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/SubReloadHSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubReloadHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubWallFollowHSM.c  .generated_files/flags/default/6d881e571c788729108aa2b45b5cd948d57a000e .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o.d" -o ${OBJECTDIR}/_ext/1736485445/SubWallFollowHSM.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/SubWallFollowHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/164314937/ES_Main.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/templates/ES_Main.c  .generated_files/flags/default/5db5a37319f1891fab0b5ddd51eeed0a32124cd9 .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/164314937" 
	@${RM} ${OBJECTDIR}/_ext/164314937/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/164314937/ES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/164314937/ES_Main.o.d" -o ${OBJECTDIR}/_ext/164314937/ES_Main.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/templates/ES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1736485445/RC_Servo.o: C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/RC_Servo.c  .generated_files/flags/default/61f56a58e4b9bcadb8091a5958c12e0b659b716f .generated_files/flags/default/af031a62ccc0c18b099f063c5edfd8e7f9b606f2
	@${MKDIR} "${OBJECTDIR}/_ext/1736485445" 
	@${RM} ${OBJECTDIR}/_ext/1736485445/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1736485445/RC_Servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"../ECE118/include" -MP -MMD -MF "${OBJECTDIR}/_ext/1736485445/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/1736485445/RC_Servo.o C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/space_jam.X/RC_Servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=5000,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   C:/Users/zoeal/OneDrive/Documents/ECE118_SpaceJam/ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=5000,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/space_jam.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
