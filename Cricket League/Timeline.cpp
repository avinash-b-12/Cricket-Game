#include <iostream>
#include <string>
#include "Timeline.h"
using namespace std;

Timeline::Timeline(){
    int i;
    for(i=0;i<6;i++){
        timeline[i]='/0';
    }
    limit=0;
}
