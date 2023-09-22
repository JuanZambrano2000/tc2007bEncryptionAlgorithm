"use client";
import React from 'react';
import Navbar from './components/navbar';

export default function Home() {
  return (
    <div className="flex flex-col min-h-screen">
      <Navbar />
      <main className="bg-gradient-to-r from-blue-400 to-purple-800 flex-grow flex flex-col justify-center items-center text-white">
        <header className="text-4xl mb-8 px-12 py-8">Activity 2 - Design of a Symmetric Encryption Algorithm</header>
        <div className="flex flex-col min-h-screen px-12">
          <p className="text-lg mb-4">
          Our team is tasked with discussing the fundamental characteristics that a robust symmetric encryption algorithm must possess. 
          These characteristics include diffusion and confusion, and you need to design a didactic symmetric encryption algorithm that 
          incorporates basic operations like bit shifting, transposition, substitution, XOR, and multiple rounds to enhance security. 
          The algorithm should also consider reversible operations and involve complex operations like multiplication and key rotations 
          if possible. After designing the algorithm, you'll need to implement it in a language of your choice, preferably one that supports
           bit-level operations. The program should encrypt alphanumeric strings using a generated symmetric key and display the ciphertext. 
           Additionally, it should decrypt the ciphertext back to the original text when provided with the same key. The assignment requires 
           a 5-minute presentation of the design and a working demonstration of the program, which should include at least two diffusion 
           operations and two confusion operations to ensure the algorithm's robustness and utility in symmetric encryption.
          </p>
          <div className="flex justify-center"> {/* Added 'flex justify-center' class here */}
            <iframe
              width="560"
              height="315"
              src="https://replit.com/@StefanoHA/Encryption?embed=1"
              title="YouTube video player"
            ></iframe>
          </div>
        </div>
      </main>
    </div>
  );
}
