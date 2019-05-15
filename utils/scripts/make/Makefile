CONTEXTFILE := /tmp/procon_context
SCRIPT = $(shell cat $(CONTEXTFILE))
UTEM := ~/github/programming_contest/utils/scripts/use_template.sh
TCAS := ~/github/programming_contest/utils/scripts/test_case.sh
FTES := ~/github/programming_contest/utils/scripts/fetch_testcase.sh
ATES := ~/github/programming_contest/utils/scripts/add_test/add_testcase.sh
FU := 
AF := 

.PHONY: new run fetch add clean copy exec all

all: run

./_$(SCRIPT): $(SCRIPT).cpp
	time g++ $(SCRIPT).cpp -o _$(SCRIPT) -std=c++14 -O2 -g -fsanitize=undefined

new: $(CONTEXTFILE)
	@$(UTEM) $(SCRIPT) $(FU)

run: $(CONTEXTFILE) ./_$(SCRIPT)
	@$(TCAS) $(SCRIPT) || echo "Test failed"

exec: $(CONTEXTFILE) ./_$(SCRIPT)
	@time ./_$(SCRIPT)

edit: $(CONTEXTFILE)
	@vim $(SCRIPT).cpp -c "call ProconEnv()"

fetch: $(CONTEXTFILE)
	@$(FTES) $(SCRIPT) $(FU)

add: $(CONTEXTFILE)
	@$(ATES) $(SCRIPT) $(AF)

af: $(CONTEXTFILE)
	@vim _$(SCRIPT)_add.txt
	@$(ATES) $(SCRIPT) _$(SCRIPT)_add.txt

copy: $(CONTEXTFILE)
	@pbcopy < $(SCRIPT).cpp

cc:
	@cat /tmp/procon_context

clean: $(CONTEXTFILE)
	@rm _$(SCRIPT) 2>/dev/null || echo "No compiled binary"
	@rm -r _$(SCRIPT).dSYM 2>/dev/null || echo "No dSYM"
	@rm .cquery 2>/dev/null || echo "No .cquery"
