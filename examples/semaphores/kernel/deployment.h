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

#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#define POK_NEEEDS_DEBUG 1

#define POK_NEEDS_THREADS 1
#define POK_NEEDS_PARTITIONS 1
#define POK_NEEDS_SCHED 1
#define POK_NEEDS_TIME 1
#define POK_NEEDS_DEBUG 1
#define POK_NEEDS_CONSOLE 1
#define POK_NEEDS_LOCKOBJECTS 1

#define POK_NEEDS_FUNCTION_TIME_GET 1
//TODO add a marco to enable edf
#define POK_NEEDS_SCHED_EDF 1
//#define POK_NEEDS_SCHED_FIFO 1
#define POK_NEEDS_GETTICK

//TODO setup scheduler of wach partition
#define POK_CONFIG_PARTITIONS_SCHEDULER {POK_SCHED_EDF,POK_SCHED_EDF}
//#define POK_CONFIG_PARTITIONS_SCHEDULER {POK_SCHED_FIFO,POK_SCHED_FIFO}

#define POK_CONFIG_NB_THREADS 7
// the num of lock objects for each partition
#define POK_CONFIG_NB_LOCKOBJECTS 1
#define POK_CONFIG_NB_PARTITIONS 2

#define POK_CONFIG_PARTITIONS_SIZE {120 * 1024, 120 * 1024};
#define POK_CONFIG_PROGRAM_NAME {"pr1/pr1.elf", "pr2/pr2.elf"};

//the size of each slot
#define POK_CONFIG_SCHEDULING_SLOTS {600000, 600000, 600000, 600000}

//time when scheduling slots are repeated
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 2400000
//specified which partition is scheduling at which slot
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION \
   {                                           \
      0, 1, 0, 1                               \
   }
#define POK_CONFIG_SCHEDULING_NBSLOTS 4

#define POK_NEEDS_THREAD_SUSPEND 1
#define POK_NEEDS_THREAD_SLEEP 1


#define POK_CONFIG_PARTITIONS_NTHREADS \
   {                                   \
      3, 2                             \
   }
#define POK_CONFIG_PARTITIONS_NLOCKOBJECTS \
   {                                       \
      1, 0                                 \
   }

typedef enum
{
   pok_part_identifier_pr1 = 0,
   pok_part_identifier_pr2 = 1
} pok_part_identifiers_t;

typedef enum
{
   pok_part_id_pr1 = 0,
   pok_part_id_pr2 = 1
} pok_part_id_t;

typedef enum
{
   pok_nodes_node1 = 0
} pok_node_id_t;

#endif
