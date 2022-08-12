#define SYS_TUI 1
#define SYS_GUI 2
#define 
typedef unsigned int size_t;

struct multi_header
{
  void* framebuffer;
  size_t bbp;
  size_t flags;
  size_t magic;
};

void brut_get_fb(struct multi_header* p)
{
  if(p->flags & SYS_TUI)
  {
    p->framebuffer = (void*)0xb8000;
    p->bbp = 4;
  }
}

struct multi_header* brut_init()
{
  struct multi_header* n = (struct multi_header*)0xCF0000;
  n->flags = SYS_TUI;
  brut_get_fb(n);
  return n;
}
