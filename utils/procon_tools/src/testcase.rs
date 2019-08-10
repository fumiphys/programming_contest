use std::fmt;

pub struct TestCase {
    input_title: String,
    output_title: String,
    input: String,
    output: String,
}

impl TestCase {
    pub fn new(input_title: String, output_title: String, input: String, output: String) -> TestCase {
        let mut processed_input = input;
        let mut processed_output = output;
        if processed_input.ends_with("\n") {
            processed_input.pop();
        }
        if processed_output.ends_with("\n") {
            processed_output.pop();
        }
        TestCase {
            input_title: input_title,
            output_title: output_title,
            input: processed_input,
            output: processed_output,
        }
    }
}

impl fmt::Display for TestCase {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} => {}",
               self.input,
               self.output,
        )
    }
}

impl fmt::Debug for TestCase {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}: {} => {}: {}",
               self.input_title,
               self.input,
               self.output_title,
               self.output,
        )
    }
}

#[test]
fn pop_last_lf() {
    let in_t = "in_t".to_string();
    let out_t = "out_t".to_string();
    let in_c = "in_c\n".to_string();
    let out_c = "out_c".to_string();
    let tc = TestCase::new(in_t, out_t, in_c.clone(), out_c.clone());
    assert!(!(in_c == tc.input));
    assert!("in_c".to_string() ==tc.input);
    assert!(out_c == tc.output);
}
