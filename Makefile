
SILENCE = @

RUNNABLE_NAME = p.exe
HOME_DIR = .

SOURCE_FOLDER = src
TEST_FOLDER =   test
UNITY_FOLDER =  test/unity
BUILD_FOLDER =  build

SOURCE_HOME = $(HOME_DIR)/$(SOURCE_FOLDER)
TEST_HOME = $(HOME_DIR)/$(TEST_FOLDER)
UNITY_HOME = $(HOME_DIR)/$(UNITY_FOLDER)
BUILD_HOME = $(HOME_DIR)/$(BUILD_FOLDER)

INCLUDES = -I$(SOURCE_HOME) -I$(TEST_HOME) -I$(UNITY_HOME)

SOURCES = $(SOURCE_HOME)/*.c
TESTS = $(TEST_HOME)/*.c
TESTS += $(UNITY_HOME)/*.c
OBJECTS = $(BUILD_HOME)/*.o

CC = gcc

all: promt_no_test \
	clean \
	create_build_folder \
	compile_sources \
	link_object_files \
	run

test: promt_test \
	clean \
	create_build_folder \
	compile_sources \
	remove_source_main \
	compile_tests \
	link_object_files\
	run

promt_no_test:
	$(SILENCE)echo "Building just the module..."

promt_test:
	$(SILENCE)echo "Building module for unit testing..."

create_build_folder:
	$(SILENCE)mkdir $(BUILD_HOME)

compile_sources:
	$(SILENCE)$(CC) -c $(INCLUDES) $(SOURCES)

remove_source_main:
	$(SILENCE)rm main.o

compile_tests:
	$(SILENCE)$(CC) -c $(INCLUDES) $(TESTS)

link_object_files:
	$(SILENCE)mv *.o $(BUILD_HOME)
	$(SILENCE)rm -rf *.o
	$(SILENCE)$(CC) -o $(BUILD_HOME)/$(RUNNABLE_NAME) $(OBJECTS)

run:
	$(SILENCE)$(BUILD_HOME)/$(RUNNABLE_NAME)

clean:
	$(SILENCE)rm -rf $(BUILD_HOME)
	$(SILENCE)rm -rf *.o
