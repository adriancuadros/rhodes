/** -*-c-*-
  This file contains YARV instructions list.
  
  ----
  This file is auto generated by insns2vm.rb
  DO NOT TOUCH!

  If you want to fix something, you must edit 'template/insns.inc.tmpl'
  or insns2vm.rb
 */


/* BIN : Basic Instruction Name */
#define BIN(n) YARVINSN_##n

enum ruby_vminsn_type {
  BIN(nop)                       = 0,

  BIN(getlocal)                  = 1,

  BIN(setlocal)                  = 2,

  BIN(getspecial)                = 3,

  BIN(setspecial)                = 4,

  BIN(getdynamic)                = 5,

  BIN(setdynamic)                = 6,

  BIN(getinstancevariable)       = 7,

  BIN(setinstancevariable)       = 8,

  BIN(getclassvariable)          = 9,

  BIN(setclassvariable)          = 10,

  BIN(getconstant)               = 11,

  BIN(setconstant)               = 12,

  BIN(getglobal)                 = 13,

  BIN(setglobal)                 = 14,

  BIN(putnil)                    = 15,

  BIN(putself)                   = 16,

  BIN(putobject)                 = 17,

  BIN(putspecialobject)          = 18,

  BIN(putiseq)                   = 19,

  BIN(putstring)                 = 20,

  BIN(concatstrings)             = 21,

  BIN(tostring)                  = 22,

  BIN(toregexp)                  = 23,

  BIN(newarray)                  = 24,

  BIN(duparray)                  = 25,

  BIN(expandarray)               = 26,

  BIN(concatarray)               = 27,

  BIN(splatarray)                = 28,

  BIN(checkincludearray)         = 29,

  BIN(newhash)                   = 30,

  BIN(newrange)                  = 31,

  BIN(pop)                       = 32,

  BIN(dup)                       = 33,

  BIN(dupn)                      = 34,

  BIN(swap)                      = 35,

  BIN(reput)                     = 36,

  BIN(topn)                      = 37,

  BIN(setn)                      = 38,

  BIN(adjuststack)               = 39,

  BIN(defined)                   = 40,

  BIN(trace)                     = 41,

  BIN(defineclass)               = 42,

  BIN(send)                      = 43,

  BIN(invokesuper)               = 44,

  BIN(invokeblock)               = 45,

  BIN(leave)                     = 46,

  BIN(finish)                    = 47,

  BIN(throw)                     = 48,

  BIN(jump)                      = 49,

  BIN(branchif)                  = 50,

  BIN(branchunless)              = 51,

  BIN(getinlinecache)            = 52,

  BIN(onceinlinecache)           = 53,

  BIN(setinlinecache)            = 54,

  BIN(opt_case_dispatch)         = 55,

  BIN(opt_checkenv)              = 56,

  BIN(opt_plus)                  = 57,

  BIN(opt_minus)                 = 58,

  BIN(opt_mult)                  = 59,

  BIN(opt_div)                   = 60,

  BIN(opt_mod)                   = 61,

  BIN(opt_eq)                    = 62,

  BIN(opt_neq)                   = 63,

  BIN(opt_lt)                    = 64,

  BIN(opt_le)                    = 65,

  BIN(opt_gt)                    = 66,

  BIN(opt_ge)                    = 67,

  BIN(opt_ltlt)                  = 68,

  BIN(opt_aref)                  = 69,

  BIN(opt_aset)                  = 70,

  BIN(opt_length)                = 71,

  BIN(opt_succ)                  = 72,

  BIN(opt_not)                   = 73,

  BIN(opt_regexpmatch1)          = 74,

  BIN(opt_regexpmatch2)          = 75,

  BIN(opt_call_c_function)       = 76,

  BIN(bitblt)                    = 77,

  BIN(answer)                    = 78,

  VM_INSTRUCTION_SIZE            = 79
};

