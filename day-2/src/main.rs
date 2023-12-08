use std::fs;
use std::fs::{File, OpenOptions};
use std::io;
use std::io::prelude::*;
use std::path::Path;
use std::env;
use std::io::Read;

// holy shit the joke program became useful

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        error_operation();
        return;
    }
    parse_challenge(args);
    return;
}
fn parse_challenge(args: Vec<String>) {
    let mut file = File::open("test.txt").expect("error: file not found");
    let mut contents = String::new();
    file.read_to_string(&mut contents).expect("can't read for some reason...");
    println!("{}", contents);
    for i in 0..contents.length()
    {
        
    }
}

fn error_operation() {
    println!("error: does not contain file");
    println!("example of how to run command: day-2 <file.txt>");
}