/*
 *                               POK header
 * 
 * The following file is a part of the POK project. Any modification should
 * made according to the POK licence. You CANNOT use this file or a part of
 * this file is this part of a file for your own project
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2009 POK team 
 *
 * Created by julien on Thu Jan 15 23:34:13 2009 
 */


#include <libc/stdio.h>
#include <core/thread.h>
//#include <core/semaphore.h>
#include <types.h>
#include <core/time.h>

extern uint8_t sid;
uint8_t val;

extern pok_thread_attr_t * tattr;

//pok_time_t job1_period=5

//period=run_time+sleep_time
pok_time_t job1_run_time=2;//s
pok_time_t job1_sleep_time=3;
void* pinger_job ()
{
   pok_time_t time=0;
   while (1)
   {
      pok_time_get(&time);
      printf ("P1T1:thread 1 begin,begin time:\t%u\n",time>>30);

      //tattr->deadline=time+job1_run_time<<30+job1_sleep_time<<20;
      while(1)
      {
         pok_time_t tmp=0;
         pok_time_get(&tmp);
         if(tmp>=time+(job1_run_time<<30))break;//ns,
      }
      pok_time_get(&time);
      printf ("P1T1:thread 1 end,end time:\t%u\n",time>>30);
      pok_thread_sleep (job1_sleep_time<<20);  ///us,pok_time_gettick
   }
}

//pok_time_t job2_period=5;
pok_time_t job2_run_time=1;
pok_time_t job2_sleep_time=4;
void* pinger_job2 ()
{
   pok_time_t time=0;
   while (1)
   {
      pok_time_get(&time);
      printf ("P1T2:thread 2 begin,begin time:\t%u\n",time>>30);
      while(1)
      {
         pok_time_t tmp=0;
         pok_time_get(&tmp);
         if(tmp>=time+(job2_run_time<<30))break;
      }
      pok_time_get(&time);
      printf ("P1T2:thread 2 end,end time:\t%u\n",time>>30);
      pok_thread_sleep (job2_sleep_time<<20);  
   }
}
