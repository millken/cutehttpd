
/**
  @author Ying Zeng (YinzCN_at_Gmail.com)
**/


#ifndef CHTD_CONN_H
#define CHTD_CONN_H


struct conn_t
{
    struct sock_t sock;
    char client_addr[40];
    char server_addr[40];
    char client_port[32];
    char server_port[32];
    time_t birthtime;
    int nRecv;
    int nSent;
    int nReqs;
    int keep_alive;
    char *reqs_strs;
    struct bufx_t *recvbufx;
    struct wker_t *wker;
    struct htdx_t *htdx;
};


struct conn_t *
conn_new(struct wker_t *);


void
conn_del(struct conn_t *);


void
conn_close(struct conn_t *);


int
conn_send(struct conn_t *, void *, int);


int
conn_recv(struct conn_t *, void *, int);


void
conn_parse_addr(struct conn_t *);


int
conn_read_until(struct conn_t *, char *, char *, int);


int
conn_recv_reqs_strs(struct conn_t *);


#endif