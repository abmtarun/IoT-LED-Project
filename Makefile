# name of your application
APPLICATION = LEDTOGGLING

# If no BOARD is found in the environment, use this default:
BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../..


DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Use a peripheral timer for the delay, if available
#FEATURES_OPTIONAL += periph_timer
 USEMODULE += ztimer_nsec
 LIBS+=-lz -lrt -lm
include $(RIOTBASE)/Makefile.include
