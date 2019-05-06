function! ProconEnv()
  vert terminal
  wincmd r
  wincmd h
  call InitScript()
endfunction

function! InitScript()
  5,20 fo
  37,47 fo
  normal G
  normal 54G
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
  silent echo system('echo ''' . a:name . ''' > /tmp/procon_context')
  silent echo system('mkdir -p test/test_' . a:name)
  silent echo system('mkdir -p test/test_' . a:name . '/in')
  silent echo system('mkdir -p test/test_' . a:name . '/out')
  execute('edit ' . l:sfile)
  if !filereadable(l:sfile)
    execute('0 r ' . s:template_file)
  endif
  call InitScript()
endfunction

" fetch test case
command! -nargs=1 Fetch call FetchTest(<f-args>)

function! FetchTest(url)
  silent echo system(s:fetch_script . ' ' . g:procon_context_name . ' ' . a:url . ' &')
endfunction

" run test
command! -nargs=0 RunTest call RunTest()

function! RunTest()
  let s:buf = term_list()[0]
  call term_sendkeys(s:buf, "make\<CR>")
endfunction
