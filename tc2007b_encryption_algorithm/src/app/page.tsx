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
          Our team is tasked with discussing the fundamental characteristics that a robust symmetric encryption algorithm must possess. These characteristics include diffusion and confusion, and you need to design a didactic symmetric encryption algorithm that incorporates basic operations like bit shifting, transposition, substitution, XOR, and multiple rounds to enhance security. The algorithm should also consider reversible operations and involve complex operations like multiplication and key rotations if possible. After designing the algorithm, you'll need to implement it in a language of your choice, preferably one that supports bit-level operations. The program should encrypt alphanumeric strings using a generated symmetric key and display the ciphertext. Additionally, it should decrypt the ciphertext back to the original text when provided with the same key. The assignment requires a 5-minute presentation of the design and a working demonstration of the program, which should include at least two diffusion operations and two confusion operations to ensure the algorithm's robustness and utility in symmetric encryption.
          </p>
          
          {/* Plain Text Field */}
          <div className="text-lg my-4">
            <p className="mb-2">Plain Text:</p>
            <textarea
              className="w-full h-24 px-16 border rounded-lg text-black focus:outline-none focus:ring focus:border-blue-300"
              placeholder="Enter plain text here..."
            ></textarea>

          {/* Encrypted Text Field */}
          <div className="text-lg my-4">
            <p className="mb-2">Encrypted Text:</p>
            <textarea
              className="w-full h-24 px-16 border rounded-lg text-black focus:outline-none focus:ring focus:border-blue-300"
              placeholder="Enter encrypted text here..."
            ></textarea>
            {/* Buttons Container */}
            <div className="flex justify-center py-4 px-8 mt-4">
              <button className="bg-green-500 text-white py-3 px-8 rounded-full hover:bg-green-600 transition duration-300 mr-4">
                Encrypt
              </button>
              <button className="bg-red-500 text-white py-3 px-8 rounded-full hover:bg-red-600 transition duration-300 ml-4">
                Decrypt
              </button>
            </div>
          </div>
          </div>
        </div>
      </main>
    </div>
  );
}
