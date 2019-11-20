#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <windows.h>

#include <k4a/k4a.h>
#include <k4a/k4atypes.h>
#include <k4abt.h>
#include <k4abttypes.h>


using namespace std;

// Error Checking Macros
#define VERIFY(result, error)                                                                            \
    if(result != K4A_RESULT_SUCCEEDED)                                                                   \
    {                                                                                                    \
        printf("%s \n - (File: %s, Function: %s, Line: %d)\n", error, __FILE__, __FUNCTION__, __LINE__); \
        exit(1);                                                                                         \
    } 

#define TIMEOUT_IN_MS 20;

// Device Capture Resources
k4a_device_t device = NULL;
k4a_device_configuration_t device_config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
k4a_capture_t device_capture = NULL;

// Body Tracking Resources
k4a_calibration_t sensor_calibration;
k4abt_tracker_t tracker = NULL;
k4abt_tracker_configuration_t tracker_config = K4ABT_TRACKER_CONFIG_DEFAULT;
k4abt_frame_t body_frame = NULL;

//Data Resources
char filename[1024] = {'\0'};
FILE* data_file = NULL;
int CONT_MODE = 1;



int init_device(void);

int init_bt(void);

int get_device_bt_capture(unsigned long* frame_number, k4abt_skeleton_t* body_skel);

int clean_up(void);

int write_output(unsigned long seq_number, unsigned long frame_number, k4abt_skeleton_t body_skel);

int do_one();

int do_continuous(unsigned long seq_len);

int parse_input(int argc, char* argv);

int init_data_file();