#ifndef GLOBAL_H
#define GLOBAL_H

void *(*proctal_global_malloc(void))(size_t);
void (*proctal_global_free(void))(void *);

#endif /* GLOBAL_H */
