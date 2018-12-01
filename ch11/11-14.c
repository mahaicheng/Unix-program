/*************************************************************************
        > 文件名: 11-14.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年10月04日 星期日 20时49分58秒
 ************************************************************************/

#include <apue.h>
#include <pthread.h>

typedef struct job {
  pthread_t j_id;
  struct job* prev;
  struct job* next;
} Job;

typedef struct queue {
  Job* q_head;
  Job* q_tail;
  pthread_rwlock_t q_lock;
} Queue;

int queue_init(Queue* qp) {
  qp->q_head = NULL;
  qp->q_tail = NULL;

  int err;
  if ((err = pthread_rwlock_init(&qp->q_lock, NULL)) != 0)
    return err;
  else
    return 0;
}

void job_insert(Queue* qp, Job* jp) {
  pthread_rwlock_wrlock(&qp->q_lock);

  if (qp->q_head == NULL) {
    qp->q_head = qp->q_tail = jp;
    jp->next = jp->prev = NULL;
  } else {
    jp->prev = NULL;
    jp->next = qp->q_head;
    qp->q_head = jp;
    jp->next->prev = jp;
  }
  pthread_rwlock_unlock(&qp->q_lock);
}

void job_append(Queue* qp, Job* jp) {
  pthread_rwlock_wrlock(&qp->q_lock);

  if (qp->q_head == NULL) {
    jp->next = jp->prev = NULL;
    qp->q_head = qp->q_tail = jp;
  } else {
    jp->next = NULL;
    jp->prev = qp->q_tail;
    qp->q_tail = jp;
    jp->prev->next = jp;
  }

  pthread_rwlock_unlock(&qp->q_lock);
}

void job_remove(Queue* qp, Job* jp) {
  pthread_rwlock_wrlock(&qp->q_lock);

  if (qp == NULL || jp == NULL) return;

  if (jp == qp->q_head && jp == qp->q_tail) {
    qp->q_head = qp->q_tail = NULL;
  } else if (jp == qp->q_tail && jp != qp->q_head) {
    qp->q_tail = jp->prev;
    qp->q_tail->next = NULL;
  } else if (jp == qp->q_head && jp != qp->q_tail) {
    qp->q_head = jp->next;
    qp->q_head->prev = NULL;
  } else {
    jp->prev->next = jp->next;
    jp->next->prev = jp->prev;
  }

  pthread_rwlock_unlock(&qp->q_lock);
}

Job* job_find(Queue* qp, pthread_t id) {
  if (qp == NULL) return NULL;

  if (pthread_rwlock_rdlock(&qp->q_lock) != 0) return NULL;

  Job* jp;
  for (jp = qp->q_head; jp != NULL; jp = jp->next) {
    if (pthread_equal(jp->j_id, id)) break;
  }

  pthread_rwlock_unlock(&qp->q_lock);
  return jp;
}
