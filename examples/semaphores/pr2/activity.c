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

//period=run_time+sleep_time
pok_time_t job1_run_time=1;//s
pok_time_t job1_sleep_time=4;

void* pinger_job ()
{
      pok_time_t time=0;
   while (1)
   {
      pok_time_get(&time);
      printf ("P2T1: begin of thread 3,begin time:\t%u------------------\n",time>>30);

      //tattr->deadline=time+job1_run_time<<20+job1_sleep_time<<20;
      while(1)
      {
         pok_time_t tmp=0;
         pok_time_get(&tmp);
         if(tmp>=time+(job1_run_time<<20))break;//ns,
      }
      pok_time_get(&time);
      printf ("P2T1:  end  of thread 3, end  time:\t%u\n",time>>30);

      pok_thread_sleep (job1_sleep_time<<20);  ///us,pok_time_gettick
   }
}

