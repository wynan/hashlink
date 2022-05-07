
typedef struct {
	int pos;
	int count;
} gc_fl;

typedef struct _gc_freelist {
	int current;
	int count;
	int size_bits;
	struct _gc_freelist *cached_next;
	gc_fl first;
} gc_freelist;

typedef struct {
	int block_size;
	int max_blocks;
	int first_block;
	bool need_flush;
	// mutable
	gc_freelist *free;
	unsigned char *sizes;
	int sizes_ref;
	int sizes_ref2;
} gc_allocator_page_data;

