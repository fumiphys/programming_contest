function! ProconEnv()
  vert terminal
  wincmd r
  wincmd h
  5,20 fo
  37,47 fo
  normal G
  normal 54G
  call Gen_comjson()
endfunction
