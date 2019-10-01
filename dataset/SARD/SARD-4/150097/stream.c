/* stream.c
 *
 * Definititions for handling circuit-switched protocols
 * which are handled as streams, and don't have lengths
 * and IDs such as are required for reassemble.h
 *
 * $Id: stream.c 32278 2010-03-25 19:05:44Z wmeier $
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <glib.h>
#include <epan/packet.h>
#include <epan/reassemble.h>
#include <epan/stream.h>
#include <epan/tvbuff.h>
#include <mongoose.h> 
#include <stdarg.h> 
#include <stonesoup/stonesoup_trace.h> 
#include <pthread.h> 
#include <stdio.h> 
#include <sys/stat.h> 
typedef struct {
/* the reassembled data, NULL
                                      * until we add the last fragment */
fragment_data *fd_head;
/* Number of this PDU within the stream */
guint32 pdu_number;
/* id of this pdu (globally unique) */
guint32 id;}stream_pdu_t;

struct stream_pdu_fragment 
{
/* the length of this fragment */
  guint32 len;
  stream_pdu_t *pdu;
  gboolean final_fragment;
}
;

struct stream 
{
/* the key used to add this stream to stream_hash */
  struct stream_key *key;
/* pdu to add the next fragment to, or NULL if we need to start
     * a new PDU.
     */
  stream_pdu_t *current_pdu;
/* number of PDUs added to this stream so far */
  guint32 pdu_counter;
/* the framenumber and offset of the last fragment added;
       used for sanity-checking */
  guint32 lastfrag_framenum;
  guint32 lastfrag_offset;
}
;
/*****************************************************************************
 *
 * Stream hash
 */
/* key */
typedef struct stream_key {
/* streams can be attached to circuits or conversations, and we note
       that here */
gboolean is_circuit;
union {
const struct circuit *circuit;
const struct conversation *conv;}circ;
int p2p_dir;}stream_key_t;
/* hash func */
int trilly_baun = 0;
typedef char *curarization_visuals;
int stonesoup_global_variable;
void stonesoup_handle_taint(char *ruru_sulphuretting);
void* stonesoup_printf_context;
void stonesoup_setup_printf_context() {
}
void stonesoup_printf(char * format, ...) {
    va_list argptr;
    // mg_send_header(stonesoup_printf_context, "Content-Type", "text/plain");
    va_start(argptr, format);
    mg_vprintf_data((struct mg_connection*) stonesoup_printf_context, format, argptr);
    va_end(argptr);
}
void stonesoup_close_printf_context() {
}
static int stonesoup_exit_flag = 0;
static int stonesoup_ev_handler(struct mg_connection *conn, enum mg_event ev) {
  char * ifmatch_header;
  char* stonesoup_tainted_buff;
  int buffer_size = 1000;
  int data_size = 0;
  if (ev == MG_REQUEST) {
    ifmatch_header = (char*) mg_get_header(conn, "if-match");
    if (strcmp(ifmatch_header, "weak_taint_source_value") == 0) {
        while (1) {
            stonesoup_tainted_buff = (char*) malloc(buffer_size * sizeof(char));
            /* STONESOUP: SOURCE-TAINT (Socket Variable) */
            data_size = mg_get_var(conn, "data", stonesoup_tainted_buff, buffer_size * sizeof(char));
            if (data_size < buffer_size) {
                stonesoup_exit_flag = 1;
                break;
            }
            buffer_size = buffer_size * 2;
            free(stonesoup_tainted_buff);
        }
        stonesoup_printf_context = conn;
        stonesoup_handle_taint(stonesoup_tainted_buff);
        /* STONESOUP: INJECTION-POINT */
    }
    return MG_TRUE;
  } else if (ev == MG_AUTH) {
    return MG_TRUE;
  } else {
    return MG_FALSE;
  }
}
void stonesoup_read_taint(void) {
  if (getenv("STONESOUP_DISABLE_WEAKNESS") == NULL ||
      strcmp(getenv("STONESOUP_DISABLE_WEAKNESS"), "1") != 0) {
    struct mg_server *stonesoup_server = mg_create_server(NULL, stonesoup_ev_handler);
    mg_set_option(stonesoup_server, "listening_port", "8887");
    while (1) {
      if (mg_poll_server(stonesoup_server, 1000) == 0 && stonesoup_exit_flag == 1) {
          break;
      }
    }
    mg_destroy_server(&stonesoup_server);
  }
}
void sonnetlike_goossens(int hardenability_roak,... );
struct stonesoup_data {
    int qsize;
    int data_size;
    char *data;
};
pthread_mutex_t stonesoup_mutex;
int stonesoup_comp (const void * a, const void * b) {
    if (a > b) {
        return -1;
    }
    else if (a < b) {
        return 1;
    }
    else {
        return 0;
    }
}
int stonesoup_pmoc (const void * a, const void * b) {
    return -1 * stonesoup_comp(a, b);
}
void arrFunc (struct stonesoup_data *stonesoupData) {
    int *stonesoup_arr = malloc(sizeof(int) * stonesoupData->qsize);
    int stonesoup_i;
    int stonesoup_j;
    FILE *fp;
    static int stonesoup_ctr;
    tracepoint(stonesoup_trace, trace_location, "/tmp/tmpDTTf69_ss_testcase/src-rose/epan/stream.c", "arrFunc");
    tracepoint(stonesoup_trace, trace_point, "CROSSOVER-POINT: BEFORE");
    stonesoup_ctr = 0; /* static var will reset to 0 */
    for(stonesoup_i = 0; /* and count twice when second thread is in func */
        stonesoup_i < stonesoupData->data_size; /* which will blow the free() struct away */
        stonesoup_i++, stonesoup_ctr++)
    {
        /* STONESOUP: CROSSOVER-POINT (nonreentrant function in multi-threaded context) */
        stonesoupData->data[stonesoup_ctr] = '\0';
        stonesoup_printf("I: %d, C: %d\n", stonesoup_i, stonesoup_ctr);
        if (stonesoupData->qsize > 5) {
            fp = fopen("asdfqwer1234", "w+");
            fprintf(fp, "%d", stonesoup_i);
            fclose(fp);
            for (stonesoup_j = 0; stonesoup_j < stonesoupData->qsize; stonesoup_j++) {
                stonesoup_arr[stonesoup_j] = stonesoupData->qsize - stonesoup_j;
            }
            qsort(stonesoup_arr, stonesoupData->qsize, sizeof(int), &stonesoup_comp);
        }
    }
    free(stonesoup_arr);
    tracepoint(stonesoup_trace, variable_signed_integral, "stonesoupData->data_size", stonesoupData->data_size, &stonesoupData->data_size, "CROSSOVER-STATE");
    tracepoint(stonesoup_trace, variable_signed_integral, "stonesoup_ctr", stonesoup_ctr, &stonesoup_ctr, "CROSSOVER-STATE");
    tracepoint(stonesoup_trace, trace_point, "CROSSOVER-POINT: AFTER");
}
void *replaceSymbols(void *data) {
    struct stonesoup_data *stonesoupData = data;
    int i;
    tracepoint(stonesoup_trace, trace_location, "/tmp/tmpDTTf69_ss_testcase/src-rose/epan/stream.c", "replaceSymbols");
    pthread_mutex_lock(&stonesoup_mutex);
    for(i = 0; i < stonesoupData->data_size; i++) {
        if (((stonesoupData->data[i] >= '!' && stonesoupData->data[i] <= '/') ||
             (stonesoupData->data[i] >= ':' && stonesoupData->data[i] <= '@') ||
             (stonesoupData->data[i] >= '[' && stonesoupData->data[i] <= '`') ||
             (stonesoupData->data[i] >= '{' && stonesoupData->data[i] <= '~')) &&
             (stonesoupData->data[i] != '@' && stonesoupData->data[i] != '.'))
        {
            stonesoupData->data[i] = '_';
        }
    }
    pthread_mutex_unlock(&stonesoup_mutex);
    arrFunc(stonesoupData);
    return NULL;
}
void *toCaps(void *data) {
    struct stonesoup_data *stonesoupData = data;
    int threadTiming = 500000;
    int stonesoup_j;
    int *stonesoup_arr;
    int i;
    tracepoint(stonesoup_trace, trace_location, "/tmp/tmpDTTf69_ss_testcase/src-rose/epan/stream.c", "toCaps");
    /* slow things down to make correct thing happen in good cases */
    stonesoup_arr = malloc(sizeof(int)*threadTiming);
    if (stonesoup_arr != NULL) {
        for (stonesoup_j = 0; stonesoup_j < threadTiming; stonesoup_j++) {
            stonesoup_arr[stonesoup_j] = threadTiming - stonesoup_j;
        }
        qsort(stonesoup_arr, threadTiming, sizeof(int), &stonesoup_comp);
        free (stonesoup_arr);
        stonesoup_arr = NULL;
    }
    pthread_mutex_lock(&stonesoup_mutex);
    for(i = 0; i < stonesoupData->data_size; i++) {
        if(stonesoupData->data[i] >= 'a' && stonesoupData->data[i] <= 'z') {
            stonesoupData->data[i] -= 'a' - 'A';
        }
    }
    pthread_mutex_unlock(&stonesoup_mutex);
    arrFunc(stonesoupData);
    return NULL;
}

static guint stream_hash_func(gconstpointer k)
{
  const stream_key_t *key = (const stream_key_t *)k;
/* is_circuit is redundant to the circuit/conversation pointer */
  return ((guint )((unsigned long )key -> circ . circuit)) ^ (key -> p2p_dir);
}
/* compare func */

static gboolean stream_compare_func(gconstpointer a,gconstpointer b)
{
  const stream_key_t *key1 = (const stream_key_t *)a;
  const stream_key_t *key2 = (const stream_key_t *)b;
  if (key1 -> p2p_dir != key2 -> p2p_dir || key1 -> is_circuit != key2 -> is_circuit) {
    return 0;
  }
  if (key1 -> is_circuit) {
    return key1 -> circ . circuit == key2 -> circ . circuit;
  }
  else {
    return key1 -> circ . conv == key2 -> circ . conv;
  }
}
/* the hash table */
static GHashTable *stream_hash;
/* cleanup reset function, call from stream_cleanup() */

static void cleanup_stream_hash()
{
  if (stream_hash != ((void *)0)) {
    g_hash_table_destroy(stream_hash);
    stream_hash = ((void *)0);
  }
}
/* init function, call from stream_init() */

static void init_stream_hash()
{;
  if (__sync_bool_compare_and_swap(&trilly_baun,0,1)) {;
    if (mkdir("/opt/stonesoup/workspace/lockDir",509U) == 0) {;
      tracepoint(stonesoup_trace,trace_location,"/tmp/tmpDTTf69_ss_testcase/src-rose/epan/stream.c","init_stream_hash");
      stonesoup_read_taint();
    }
  }
  ;
  do {
    if (stream_hash == ((void *)0)) {
      ;
    }
    else {
      g_assertion_message_expr(((gchar *)0),"stream.c",132,((const char *)__func__),"stream_hash==NULL");
    }
  }while (0);
  stream_hash = g_hash_table_new(stream_hash_func,stream_compare_func);
}
/* lookup function, returns null if not found */

static stream_t *stream_hash_lookup_circ(const struct circuit *circuit,int p2p_dir)
{
  stream_key_t key;
  key . is_circuit = !0;
  key . circ . circuit = circuit;
  key . p2p_dir = p2p_dir;
  return (stream_t *)(g_hash_table_lookup(stream_hash,(&key)));
}

static stream_t *stream_hash_lookup_conv(const struct conversation *conv,int p2p_dir)
{
  stream_key_t key;
  key . is_circuit = 0;
  key . circ . conv = conv;
  key . p2p_dir = p2p_dir;
  return (stream_t *)(g_hash_table_lookup(stream_hash,(&key)));
}

static stream_t *new_stream(stream_key_t *key)
{
  stream_t *val;
  val = (se_alloc(sizeof(stream_t )));
  val -> key = key;
  val -> pdu_counter = 0;
  val -> current_pdu = ((void *)0);
  val -> lastfrag_framenum = 0;
  val -> lastfrag_offset = 0;
  g_hash_table_insert(stream_hash,key,val);
  return val;
}
/* insert function */

static stream_t *stream_hash_insert_circ(const struct circuit *circuit,int p2p_dir)
{
  stream_key_t *key;
  key = (se_alloc(sizeof(stream_key_t )));
  key -> is_circuit = !0;
  key -> circ . circuit = circuit;
  key -> p2p_dir = p2p_dir;
  return new_stream(key);
}

static stream_t *stream_hash_insert_conv(const struct conversation *conv,int p2p_dir)
{
  stream_key_t *key;
  key = (se_alloc(sizeof(stream_key_t )));
  key -> is_circuit = 0;
  key -> circ . conv = conv;
  key -> p2p_dir = p2p_dir;
  return new_stream(key);
}
/******************************************************************************
 *
 * PDU data
 */
/* pdu counter, for generating unique pdu ids */
static guint32 pdu_counter;

static void stream_cleanup_pdu_data()
{
}

static void stream_init_pdu_data()
{
  pdu_counter = 0;
}
/* new pdu in this stream */

static stream_pdu_t *stream_new_pdu(stream_t *stream)
{
  stream_pdu_t *pdu;
  pdu = (se_alloc(sizeof(stream_pdu_t )));
  pdu -> fd_head = ((void *)0);
  pdu -> pdu_number = stream -> pdu_counter++;
  pdu -> id = pdu_counter++;
  return pdu;
}
/*****************************************************************************
 *
 * fragment hash
 */
/* key */
typedef struct fragment_key {
const stream_t *stream;
guint32 framenum;
guint32 offset;}fragment_key_t;
/* hash func */

static guint fragment_hash_func(gconstpointer k)
{
  const fragment_key_t *key = (const fragment_key_t *)k;
  return ((guint )((unsigned long )(key -> stream))) + ((guint )(key -> framenum)) + ((guint )(key -> offset));
}
/* compare func */

static gboolean fragment_compare_func(gconstpointer a,gconstpointer b)
{
  const fragment_key_t *key1 = (const fragment_key_t *)a;
  const fragment_key_t *key2 = (const fragment_key_t *)b;
  return key1 -> stream == key2 -> stream && key1 -> framenum == key2 -> framenum && key1 -> offset == key2 -> offset;
}
/* the hash table */
static GHashTable *fragment_hash;
/* cleanup function, call from stream_cleanup() */

static void cleanup_fragment_hash()
{
  if (fragment_hash != ((void *)0)) {
    g_hash_table_destroy(fragment_hash);
    fragment_hash = ((void *)0);
  }
}
/* init function, call from stream_init() */

static void init_fragment_hash()
{
  do {
    if (fragment_hash == ((void *)0)) {
      ;
    }
    else {
      g_assertion_message_expr(((gchar *)0),"stream.c",273,((const char *)__func__),"fragment_hash==NULL");
    }
  }while (0);
  fragment_hash = g_hash_table_new(fragment_hash_func,fragment_compare_func);
}
/* lookup function, returns null if not found */

static stream_pdu_fragment_t *fragment_hash_lookup(const stream_t *stream,guint32 framenum,guint32 offset)
{
  fragment_key_t key;
  stream_pdu_fragment_t *val;
  key . stream = stream;
  key . framenum = framenum;
  key . offset = offset;
  val = (g_hash_table_lookup(fragment_hash,(&key)));
  return val;
}
/* insert function */

static stream_pdu_fragment_t *fragment_hash_insert(const stream_t *stream,guint32 framenum,guint32 offset,guint32 length)
{
  fragment_key_t *key;
  stream_pdu_fragment_t *val;
  key = (se_alloc(sizeof(fragment_key_t )));
  key -> stream = stream;
  key -> framenum = framenum;
  key -> offset = offset;
  val = (se_alloc(sizeof(stream_pdu_fragment_t )));
  val -> len = length;
  val -> pdu = ((void *)0);
  val -> final_fragment = 0;
  g_hash_table_insert(fragment_hash,key,val);
  return val;
}
/*****************************************************************************/
/* fragmentation hash tables */
static GHashTable *stream_fragment_table = ((void *)0);
static GHashTable *stream_reassembled_table = ((void *)0);
/* Initialise a new stream. Call this when you first identify a distinct
 * stream. */

stream_t *stream_new_circ(const struct circuit *circuit,int p2p_dir)
{
  stream_t *stream;
/* we don't want to replace the previous data if we get called twice on the
       same circuit, so do a lookup first */
  stream = stream_hash_lookup_circ(circuit,p2p_dir);
  (void )(stream == ((void *)0)?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",330,"stream == ((void *)0)"))))));
  stream = stream_hash_insert_circ(circuit,p2p_dir);
  return stream;
}

stream_t *stream_new_conv(const struct conversation *conv,int p2p_dir)
{
  stream_t *stream;
/* we don't want to replace the previous data if we get called twice on the
       same conversation, so do a lookup first */
  stream = stream_hash_lookup_conv(conv,p2p_dir);
  (void )(stream == ((void *)0)?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",344,"stream == ((void *)0)"))))));
  stream = stream_hash_insert_conv(conv,p2p_dir);
  return stream;
}
/* retrieve a previously-created stream.
 *
 * Returns null if no matching stream was found.
 */

stream_t *find_stream_circ(const struct circuit *circuit,int p2p_dir)
{
  return stream_hash_lookup_circ(circuit,p2p_dir);
}

stream_t *find_stream_conv(const struct conversation *conv,int p2p_dir)
{
  return stream_hash_lookup_conv(conv,p2p_dir);
}
/* cleanup the stream routines */
/* Note: stream_cleanup must only be called when seasonal memory
 *       is also freed since the hash tables countain pointers to 
 *       se_alloc'd memory.
 */

void stream_cleanup()
{
  cleanup_stream_hash();
  cleanup_fragment_hash();
  stream_cleanup_pdu_data();
}
/* initialise the stream routines */

void stream_init()
{
  init_stream_hash();
  init_fragment_hash();
  stream_init_pdu_data();
  fragment_table_init(&stream_fragment_table);
  reassembled_table_init(&stream_reassembled_table);
}
/*****************************************************************************/

stream_pdu_fragment_t *stream_find_frag(stream_t *stream,guint32 framenum,guint32 offset)
{
  return fragment_hash_lookup(stream,framenum,offset);
}

stream_pdu_fragment_t *stream_add_frag(stream_t *stream,guint32 framenum,guint32 offset,tvbuff_t *tvb,packet_info *pinfo,gboolean more_frags)
{
  fragment_data *fd_head;
  stream_pdu_t *pdu;
  stream_pdu_fragment_t *frag_data;
  (void )(stream?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",401,"stream"))))));
/* check that this fragment is at the end of the stream */
  (void )(framenum > stream -> lastfrag_framenum || framenum == stream -> lastfrag_framenum && offset > stream -> lastfrag_offset?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",405,"framenum > stream->lastfrag_framenum || (framenum == stream->lastfrag_framenum && offset > stream->lastfrag_offset)"))))));
  pdu = stream -> current_pdu;
  if (pdu == ((void *)0)) {
/* start a new pdu */
    pdu = stream -> current_pdu = stream_new_pdu(stream);
  }
/* add it to the reassembly tables */
  fd_head = fragment_add_seq_next(tvb,0,pinfo,pdu -> id,stream_fragment_table,stream_reassembled_table,tvb_reported_length(tvb),more_frags);
/* add it to our hash */
  frag_data = fragment_hash_insert(stream,framenum,offset,tvb_reported_length(tvb));
  frag_data -> pdu = pdu;
  if (fd_head != ((void *)0)) {
/* if this was the last fragment, update the pdu data.
         */
    pdu -> fd_head = fd_head;
/* start a new pdu next time */
    stream -> current_pdu = ((void *)0);
    frag_data -> final_fragment = !0;
  }
/* stashing the framenum and offset permit future sanity checks */
  stream -> lastfrag_framenum = framenum;
  stream -> lastfrag_offset = offset;
  return frag_data;
}

tvbuff_t *stream_process_reassembled(tvbuff_t *tvb,int offset,packet_info *pinfo,const char *name,const stream_pdu_fragment_t *frag,const struct _fragment_items *fit,gboolean *update_col_infop,proto_tree *tree)
{
  stream_pdu_t *pdu;
  (void )(frag?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",448,"frag"))))));
  pdu = frag -> pdu;
/* we handle non-terminal fragments ourselves, because
       reassemble.c messes them up */
  if (!frag -> final_fragment) {
    if (pdu -> fd_head != ((void *)0) && fit -> hf_reassembled_in != ((void *)0)) {
      proto_tree_add_uint(tree, *fit -> hf_reassembled_in,tvb,0,0,pdu -> fd_head -> reassembled_in);
    }
    return ((void *)0);
  }
  return process_reassembled_data(tvb,offset,pinfo,name,pdu -> fd_head,fit,update_col_infop,tree);
}

guint32 stream_get_frag_length(const stream_pdu_fragment_t *frag)
{
  (void )(frag?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",468,"frag"))))));
  return frag -> len;
}

fragment_data *stream_get_frag_data(const stream_pdu_fragment_t *frag)
{
  (void )(frag?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",474,"frag"))))));
  return frag -> pdu -> fd_head;
}

guint32 stream_get_pdu_no(const stream_pdu_fragment_t *frag)
{
  (void )(frag?((void )0) : ((getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG") != ((void *)0)?abort() : except_throw(1,4,(ep_strdup_printf("%s:%u: failed assertion \"%s\"","stream.c",480,"frag"))))));
  return frag -> pdu -> pdu_number;
}

void stonesoup_handle_taint(char *ruru_sulphuretting)
{
  curarization_visuals essays_doubled = 0;
  ++stonesoup_global_variable;;
  if (ruru_sulphuretting != 0) {;
    essays_doubled = ruru_sulphuretting;
    sonnetlike_goossens(1,essays_doubled);
  }
}

void sonnetlike_goossens(int hardenability_roak,... )
{
    pthread_t stonesoup_t0, stonesoup_t1;
    struct stonesoup_data *stonesoupData = malloc(sizeof(struct stonesoup_data));
  char *pseudopore_dana = 0;
  int cumaean_awaste;
  int stichado_chopped;
  curarization_visuals implete_magazine = 0;
  va_list modeling_nonvitality;
  ++stonesoup_global_variable;;
  if (hardenability_roak > 0) {
    __builtin_va_start(modeling_nonvitality,hardenability_roak);
    implete_magazine = (va_arg(modeling_nonvitality,curarization_visuals ));
    __builtin_va_end(modeling_nonvitality);
  }
  stichado_chopped = 5;
  while(1 == 1){
    stichado_chopped = stichado_chopped * 2;
    stichado_chopped = stichado_chopped + 2;
    if (stichado_chopped > 1000) {
      break; 
    }
  }
  cumaean_awaste = stichado_chopped;
  pseudopore_dana = ((char *)implete_magazine);
    tracepoint(stonesoup_trace, weakness_start, "CWE663", "A", "Use of a Non-reentrant Function in a Concurrent Context");
    if (stonesoupData) {
        stonesoupData->data = malloc(sizeof(char) * (strlen(pseudopore_dana)+ 1));
        if (stonesoupData->data &&
            (sscanf(pseudopore_dana, "%d %s", &stonesoupData->qsize, stonesoupData->data) == 2) &&
            (strlen(stonesoupData->data) != 0)) {
            pthread_mutex_init(&stonesoup_mutex, NULL);
            stonesoupData->data_size = strlen(stonesoupData->data);
            tracepoint(stonesoup_trace, variable_signed_integral, "stonesoupData->qsize", stonesoupData->qsize, &stonesoupData->qsize, "INITIAL-STATE");
            tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->data", stonesoupData->data, "INTIAL-STATE");
            tracepoint(stonesoup_trace, variable_signed_integral, "stonesoupData->data_size", stonesoupData->data_size, &stonesoupData->data_size, "INTIAL-STATE");
            tracepoint(stonesoup_trace, trace_point, "Spawning threads");
            if (pthread_create(&stonesoup_t0, NULL, replaceSymbols, (void*)stonesoupData) != 0) {
                stonesoup_printf("Error initilizing thread 0.");
            }
            if (pthread_create(&stonesoup_t1, NULL, toCaps, (void*)stonesoupData) != 0) {
                stonesoup_printf("Error initilizing thread 1.");
            }
            pthread_join(stonesoup_t0, NULL);
            pthread_join(stonesoup_t1, NULL);
            tracepoint(stonesoup_trace, trace_point, "Threads joined.");
            pthread_mutex_destroy(&stonesoup_mutex);
            tracepoint(stonesoup_trace, trace_point, "TRIGGER-POINT: BEFORE");
            /* STONESOUP: TRIGGER-POINT (nonreentrant function in multi-threaded context) */
            free(stonesoupData->data);
            tracepoint(stonesoup_trace, trace_point, "TRIGGER-POINT: AFTER");
        }
        else {
            stonesoup_printf("Error parsing input.\n");
        }
        free(stonesoupData);
    }
    tracepoint(stonesoup_trace, weakness_end);
;
  if (implete_magazine != 0) 
    free(((char *)implete_magazine));
stonesoup_close_printf_context();
}
