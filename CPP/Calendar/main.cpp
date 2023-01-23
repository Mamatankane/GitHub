#include <iostream>
#include "Calendar.h"
#include <vector>
#include "Utils.h"
#include "Event.h"
using namespace std;

int main(){
    Calendar cal1(get_api_results(10,1000));
    Calendar cal2(get_api_results(0,1000));
   long int now= cal1.getFirstEvent()->start;
   cout<<cal1.getUpcomingEvent(now)<<endl;
   cout<<cal2.getUpcomingEvent(now)<<endl;
    cout<<"=================================="<<endl;
   string type=cal1.getFirstEvent()->type;
   long int end= cal1.getFirstEvent()->end;
   int id=cal1.getFirstEvent()->id;
   for (int i=0; i<cal1.filterEvents(&id,&now,&end,&type).size(); i++){
        cout<<cal1.filterEvents(&id,&now,&end,&type)[i]<<endl;
   }
   cout<<"=================================="<<endl;
  end=  cal2.getFirstEvent()->end;
  type= cal2.getFirstEvent()->type;
  cout<<cal2<<endl<<cal1;
    cout<<"=================================="<<endl;
   cal1.alterEvent(id,&end, &type);
  cal2.removeEvent(id);
   cal1.removeEvent(id);
  cout<<cal2<<endl<<cal1;
   cout<<"=================================="<<endl;
  cal2.clearCalendar();
 cout<<cal2<<endl<<cal1;
   cout<<"=================================="<<endl;
   return 0;
}