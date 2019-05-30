function! ProconEnv()
  vert terminal
  wincmd r
  wincmd h
  call InitScript()
endfunction

function! InitScript()
  5,26 fo
  44,54 fo
  normal G
  normal 62G
  call Gen_comjson()
endfunction

let g:procon_context_name = system('cat /tmp/procon_context | tr -cd ''0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-''')
let s:fetch_script = '~/github/programming_contest/utils/scripts/fetch_testcase.sh'
let s:template_file = '~/github/programming_contest/template/template.cpp'

" change context
command! -nargs=1 Chcon call ChangeContext(<f-args>)

function! ChangeContext(name)
  let g:procon_context_name = a:name
  let l:sfile = fnamemodify(a:name . '.cpp', ':p')
  call RunTerm("chcon " . a:name ."\<CR>")
  execute('edit ' . l:sfile)
  if !filereadable(l:sfile)
    execute('0 r ' . s:template_file)
    w
  endif
  call InitScript()
endfunction

" fetch test case
command! -nargs=1 Fetch call FetchTest(<f-args>)

function! FetchTest(url)
  silent echo system(s:fetch_script . ' ' . g:procon_context_name . ' ' . a:url . ' &')
  call RunTerm("make fetch FU=" . a:url . " \<CR>")
endfunction

" run test
command! -nargs=0 RunTest call RunTest()

function! RunTest()
  call RunTerm("make\<CR>")
endfunction

" copy
command! -nargs=0 RunCopy call RunCopy()

function! RunCopy()
  call RunTerm("make copy\<CR>")
endfunction

function! RunTerm(com)
  let s:buf = term_list()[0]
  call term_sendkeys(s:buf, a:com)
endfunction
