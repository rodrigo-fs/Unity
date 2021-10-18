
#include "payment.h"
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int payment(float value, char status[15]){
	const char *status_values[4];
	status_values[0] = "regular"; 
	status_values[1] = "estudante";
	status_values[2] = "aposentado";
	status_values[3] = "vip";
	//Set status to lower
	int valid_status = 0;
	char *p = status;
	for( ; *p; ++p) *p = tolower(*p);
	for(int i = 0; i < 4; i++){
		if(strcmp(status, status_values[i]) == 0){
			valid_status = 1;
		}
	}
	if(valid_status == 0)
		return 1;
	
	if(!((value > 0.010f || fabs(value-0.01f) < 0.001f) && (value < 99999.000f || fabs(value-99999.000f) < 0.001f))){
		return 2;
	}

	return 0;
}
