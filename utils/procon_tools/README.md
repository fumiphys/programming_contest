# procon\_tools
## install
```
pip install -e .
```

## requirement
 - GNU time

## about
 - scirpt for programming contest
 - fetch testcase from contest site
 - (files will be written in .procon dir)

## fetch
```
pc fetch (--host {contest host}) --contest {contest_name} --problem {problem_name}
```
 - default host: AtCoder
 - currently supported: AtCoder, yukicoder

## test
```
pc test --source {source_file}
```
 - currently supported: C++(extension: cpp, cc), Python3(extension: py, py3)


## other
 - you can omit argument [host, contest, problem] once you specify them.
