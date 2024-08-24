let () = Plugin.load Sys.argv.(1)
open Prelude
open Constants
open Constants.K
open Run
let () = Sys.catch_break true
let () = Gc.set { (Gc.get()) with Gc.minor_heap_size = 33554432 }let input = Lexer.parse_k_binary_string
"\x7fKAST\x04\x00\x01\x02\x00\x00\x00\x00\x00\x00\x00\x04\x00.\x00M\x00a\x00p\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x04\x00$\x00P\x00G\x00M\x00\x00\x00\x00\x00\x00\x00\n\x00K\x00C\x00o\x00n\x00f\x00i\x00g\x00V\x00a\x00r\x01\x00\x00\x00\x00\x00\x00\x00\x10\x00D\x00a\x00t\x00a\x00_\x00R\x00a\x00c\x00e\x00_\x001\x006\x00_\x00b\x00a\x00d\x00\x00\x00\x00\x00\x00\x00\x02\x00I\x00d\x02\x00\x00\x00\x00\x00\x00\x00\x17\x00.\x00L\x00i\x00s\x00t\x00{\x00\"\x00_\x00,\x00_\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\"\x00}\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x12\x00#\x00v\x00o\x00i\x00d\x00T\x00y\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x05\x00d\x00a\x00t\x00a\x001\x00\x00\x00\x04\x02\x00\x00\x00\x00\x00\x00\x00\x05\x00#\x00d\x00e\x00c\x00l\x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00\x05\x00d\x00a\x00t\x00a\x002\x00\x00\x00\x06\x02\x00\x00\x00\x02\x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00\t\x00s\x00h\x00a\x00r\x00e\x00_\x00v\x00a\x00r\x00\x00\x00\x07\x02\x00\x00\x00\x03\x00\x00\x00\x00\x01\x02\x00\x00\x00\x00\x00\x00\x00\x0f\x00c\x00o\x00p\x00y\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x0f\x00.\x00L\x00i\x00s\x00t\x00{\x00\"\x00#\x00p\x00r\x00o\x00p\x00s\x00\"\x00}\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x06\x00#\x00p\x00r\x00o\x00p\x00s\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\x19\x00n\x00e\x00w\x00R\x00e\x00s\x00o\x00u\x00r\x00c\x00e\x00(\x00_\x00)\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x01\x01\x00\x00\x00\x05\x00\x00\x00\x0b\x02\x00\x00\x00\x00\x00\x00\x00\t\x00#\x00t\x00r\x00a\x00n\x00s\x00f\x00e\x00r\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\x12\x00#\x00u\x00n\x00i\x00n\x00i\x00t\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x00\x01\x00\x00\x00\n\x00\x00\x00\r\x02\x00\x00\x00\x00\x00\x00\x00\x16\x00t\x00r\x00a\x00n\x00s\x00f\x00e\x00r\x00_\x00_\x00;\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x02\x02\x00\x00\x00\x02\x00\x00\x00\x00\x00\x01\x00\x00\x00\t\x00\x00\x00\x0e\x02\x00\x00\x00\x01\x00\x00\x00\x00\x02\x01\x00\x00\x00\x0b\x00\x00\x00\x0e\x01\x00\x00\x00\b\x00\x00\x00\x0e\x02\x00\x00\x00\x00\x00\x00\x00\b\x00#\x00m\x00b\x00o\x00r\x00r\x00o\x00w\x00\x00\x00\x00\x02\x01\x00\x00\x00\n\x00\x00\x00\x0f\x01\x00\x00\x00\t\x00\x00\x00\x0f\x02\x00\x00\x00\x00\x00\x00\x00\x07\x00#\x00b\x00o\x00r\x00r\x00o\x00w\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\x16\x00.\x00L\x00i\x00s\x00t\x00{\x00\"\x00_\x00_\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\"\x00}\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\r\x00_\x00_\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x02\x02\x00\x00\x00\x01\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\x06\x00#\x00b\x00l\x00o\x00c\x00k\x00\x00\x00\x00\x01\x02\x00\x00\x00\x00\x00\x00\x00\x07\x00#\x00r\x00e\x00p\x00e\x00a\x00t\x00\x00\x00\x00\x01\x02\x00\x00\x00\r\x00\x00\x00\x00\x00\x02\x00\x00\x00\x0c\x00\x00\x00\x00\x00\x02\x00\x00\x00\x0b\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x01\x01\x00\x00\x00\x11\x00\x00\x00\x14\x02\x00\x00\x00\x00\x00\x00\x00\r\x00*\x00_\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x01\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\x05\x00\x00\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x03\x00\x00\x00\x00\x01\x02\x00\x00\x00\x02\x00\x00\x00\x00\x01\x02\x00\x00\x00\x05\x00\x00\x00\x00\x00\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x03\x00\x00\x00\x00\x01\x02\x00\x00\x00\x00\x00\x00\x00\t\x00#\x00f\x00u\x00n\x00c\x00t\x00i\x00o\x00n\x00\x00\x00\x00\x04\x02\x00\x00\x00\x00\x00\x00\x00\r\x00_\x00;\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00\x11\x00D\x00a\x00t\x00a\x00_\x00R\x00a\x00c\x00e\x00_\x001\x006\x00_\x00g\x00o\x00o\x00d\x00\x00\x00\x18\x02\x00\x00\x00\x17\x00\x00\x00\x00\x00\x02\x00\x00\x00\x16\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x05\x00d\x00a\x00t\x00a\x003\x00\x00\x00\x19\x02\x00\x00\x00\x15\x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00\x05\x00d\x00a\x00t\x00a\x004\x00\x00\x00\x1a\x02\x00\x00\x00\x16\x00\x00\x00\x00\x01\x01\x00\x00\x00\x14\x00\x00\x00\x1a\x02\x00\x00\x00\x16\x00\x00\x00\x00\x01\x02\x00\x00\x00\x13\x00\x00\x00\x00\x00\x02\x00\x00\x00\x12\x00\x00\x00\x00\x00\x02\x00\x00\x00\x11\x00\x00\x00\x00\x02\x02\x00\x00\x00\x10\x00\x00\x00\x00\x01\x01\x00\x00\x00\x14\x00\x00\x00\x1a\x02\x00\x00\x00\x0f\x00\x00\x00\x00\x02\x02\x00\x00\x00\x0e\x00\x00\x00\x00\x00\x01\x00\x00\x00\x02\x00\x00\x00\x1a\x02\x00\x00\x00\r\x00\x00\x00\x00\x02\x02\x00\x00\x00\x0e\x00\x00\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x1a\x02\x00\x00\x00\r\x00\x00\x00\x00\x02\x01\x00\x00\x00\x02\x00\x00\x00\x1a\x01\x00\x00\x00\x14\x00\x00\x00\x1a\x02\x00\x00\x00\x0b\x00\x00\x00\x00\x02\x01\x00\x00\x00\x01\x00\x00\x00\x1a\x01\x00\x00\x00\x14\x00\x00\x00\x1a\x02\x00\x00\x00\x0b\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x00\x02\x00\x00\x00\t\x00\x00\x00\x00\x02\x02\x00\x00\x00\t\x00\x00\x00\x00\x02\x02\x00\x00\x00\b\x00\x00\x00\x00\x01\x02\x00\x00\x00\x07\x00\x00\x00\x00\x01\x01\x00\x00\x00\x02\x00\x00\x00\x1a\x02\x00\x00\x00\x06\x00\x00\x00\x00\x01\x02\x00\x00\x00\x00\x00\x00\x00\b\x00#\x00e\x00x\x00p\x00S\x00t\x00m\x00t\x00\x00\x00\x00\x01\x01\x00\x00\x00\x02\x00\x00\x00\x1b\x02\x00\x00\x00\x07\x00\x00\x00\x00\x01\x02\x00\x00\x00\x01\x00\x00\x00\x00\x01\x02\x00\x00\x00\x0b\x00\x00\x00\x00\x00\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\t\x00\x00\x00\x00\x01\x02\x00\x00\x00\b\x00\x00\x00\x00\x01\x02\x00\x00\x00\x0b\x00\x00\x00\x00\x00\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\n\x00\x00\x00\x00\x02\x02\x00\x00\x00\t\x00\x00\x00\x00\x01\x02\x00\x00\x00\x06\x00\x00\x00\x00\x04\x02\x00\x00\x00\x05\x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00\x04\x00m\x00a\x00i\x00n\x00\x00\x00\x1c\x01\x00\x00\x00\x00\x00\x00\x00\x04\x00a\x00r\x00g\x00c\x00\x00\x00\x1d\x02\x00\x00\x00\x16\x00\x00\x00\x00\x00\x02\x00\x00\x00\x15\x00\x00\x00\x00\x00\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\x04\x00#\x00o\x00w\x00n\x00\x00\x00\x00\x01\x02\x00\x00\x00\x00\x00\x00\x00\n\x00#\x00p\x00a\x00r\x00a\x00m\x00e\x00t\x00e\x00r\x00\x00\x00\x00\x02\x01\x00\x00\x00\x00\x00\x00\x00\x04\x00a\x00r\x00g\x00v\x00\x00\x00 \x02\x00\x00\x00\x18\x00\x00\x00\x00\x00\x02\x00\x00\x00\x03\x00\x00\x00\x00\x01\x02\x00\x00\x00\x02\x00\x00\x00\x00\x02\x02\x00\x00\x00\x1f\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x0e\x00_\x00,\x00_\x00_\x00O\x00S\x00L\x00-\x00S\x00Y\x00N\x00T\x00A\x00X\x00\x00\x00\x00\x02\x02\x00\x00\x00\x01\x00\x00\x00\x00\x02\x02\x00\x00\x00\x1a\x00\x00\x00\x00\x00\x02\x00\x00\x00\x19\x00\x00\x00\x00\x00\x02\x00\x00\x00\x18\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x01\x01\x00\x00\x00\n\x00\x00\x00!\x02\x00\x00\x00 \x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x07\x00#\x00F\x00n\x00C\x00a\x00l\x00l\x00\x00\x00\x00\x02\x02\x00\x00\x00\b\x00\x00\x00\x00\x01\x01\x00\x00\x00#\x00\x00\x00\"\x02\x00\x00\x00!\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x00\x02\x02\x00\x00\x00\b\x00\x00\x00\x00\x01\x02\x00\x00\x00\x1b\x00\x00\x00\x00\x00\x02\x00\x00\x00\x1a\x00\x00\x00\x00\x00\x02\x00\x00\x00\x19\x00\x00\x00\x00\x02\x02\x00\x00\x00\x18\x00\x00\x00\x00\x01\x02\x00\x00\x00\x00\x00\x00\x00\x03\x00v\x00a\x00l\x00\x00\x00\x00\x01\x02\x00\x00\x00\x13\x00\x00\x00\x00\x00\x02\x00\x00\x00\x12\x00\x00\x00\x00\x02\x02\x00\x00\x00\x12\x00\x00\x00\x00\x02\x02\x00\x00\x00\x12\x00\x00\x00\x00\x02\x02\x00\x00\x00\x11\x00\x00\x00\x00\x01\x02\x00\x00\x00\x0e\x00\x00\x00\x00\x04\x02\x00\x00\x00\r\x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00\x04\x00a\x00r\x00g\x001\x00\x00\x00$\x02\x00\x00\x00 \x00\x00\x00\x00\x01\x01\x00\x00\x00\x00\x00\x00\x00\x05\x00a\x00r\x00g\x00v\x001\x00\x00\x00%\x02\x00\x00\x00!\x00\x00\x00\x00\x01\x02\x00\x00\x00\x1e\x00\x00\x00\x00\x00\x02\x00\x00\x00\x1d\x00\x00\x00\x00\x00\x02\x00\x00\x00\x1c\x00\x00\x00\x00\x02\x02\x00\x00\x00\x1b\x00\x00\x00\x00\x01\x01\x00\x00\x00\x02\x00\x00\x00%\x02\x00\x00\x00\x1a\x00\x00\x00\x00\x02\x02\x00\x00\x00\x1d\x00\x00\x00\x00\x00\x02\x00\x00\x00\x1b\x00\x00\x00\x00\x01\x01\x00\x00\x00\x01\x00\x00\x00%\x02\x00\x00\x00\x1a\x00\x00\x00\x00\x02\x01\x00\x00\x00\n\x00\x00\x00%\x01\x00\x00\x00\x02\x00\x00\x00%\x01\x00\x00\x00\x01\x00\x00\x00%\x02\x00\x00\x00$\x00\x00\x00\x00\x00\x02\x00\x00\x00\x05\x00\x00\x00\x00\x02\x02\x00\x00\x00\x05\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x02\x00\x00\x00\x0b\x00\x00\x00\x00\x01\x02\x00\x00\x00\x15\x00\x00\x00\x00\x00\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x14\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\x05\x00_\x00|\x00-\x00>\x00_\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\x05\x00_\x00M\x00a\x00p\x00_\x00\x00\x00\x00\x02\x01\x00\x00\x00\x00\x00\x00\x00\x06\x00$\x00S\x00T\x00D\x00I\x00N\x00\x00\x00*\x01\x00\x00\x00\x00\x00\x00\x00\x02\x00\"\x00\"\x00\x00\x00\x00\x00\x00\x00\x06\x00S\x00t\x00r\x00i\x00n\x00g\x02\x00\x00\x00\x05\x00\x00\x00\x00\x02\x02\x00\x00\x00\x04\x00\x00\x00\x00\x02\x01\x00\x00\x00\x00\x00\x00\x00\x03\x00$\x00I\x00O\x00\x00\x00-\x01\x00\x00\x00\x00\x00\x00\x00\x04\x00\"\x00o\x00n\x00\"\x00\x00\x00\x03\x02\x00\x00\x00\x07\x00\x00\x00\x00\x02\x02\x00\x00\x00\x06\x00\x00\x00\x00\x02\x02\x00\x00\x00\x00\x00\x00\x00\t\x00i\x00n\x00i\x00t\x00T\x00C\x00e\x00l\x00l\x00\x00\x00\x00\x01\x07"
let out = open_out_bin "/home/user/workspace/model/./.krun-2020-09-02-08-28-41-736-90af2a5f-0d9d-4656-97b9-48903777b9ec/run.out"
let res, steps = run_no_thread_opt(input) (-1) 
let () = output_string out ((string_of_int steps) ^ "\n" ^ print_k_binary(res))
