# procon\_tools
## description
This is a tool for local execution.

## requirement
 - GNU time (this will be optional in the future)

## install
```
pip install -e .
```

## functions
 - copy content of script
 - fetch testcases
 - interactive runner
 - run script
 - run testcases

## to be implemented
 - add testcase
 - login

## copy
```
pc copy --source {source_file}
```

## fetch
```
pc fetch (--host {contest host}) --contest {contest_name} --problem {problem_name}
```
 - default host: AtCoder
 - currently supported: AtCoder, yukicoder, Codeforces

### fetchurl
```
pc fetchurl (--host {contest host}) --contest {contest_name} --problem {problem_name} --url {url}
```

## interactive
```
pc interactive --source {sourcefile} --judge {judge_file}
```

## run
```
pc run --source {source_file}
```

## test
```
pc test --source {source_file}
```

## other
 - You can omit argument (host, contest, problem etc.) once you specify them.
 - Supported languages are: C++(cpp, cc), Python(py, py3)
 - In default, compilation will be skipped if no changes are made to source file. You can compile source by adding `--force` option.
 - Default compilation option for C++ is `-std=c++14 -O2 -g -fsanitize=undefined` which will take long time to compile. You can use fast compilation of only `-std=c++14` by adding `--fast`.
 - Default timeout for execution is 20s.
 - You can change settings by editing [config.py](./config.py).

## testing
```
pytest -v (--cov=".")
```
- (future) for testing copy method at headless environment, you should run `xvfb-run pytest -v`
