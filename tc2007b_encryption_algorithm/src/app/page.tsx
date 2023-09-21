import React from 'react';
import Navbar from './components/navbar';

export default function Home() {
  return (
    <div className="flex flex-col min-h-screen">
      <Navbar />
      <main className="bg-gradient-to-r from-blue-400 to-purple-500 flex-grow flex flex-col justify-center items-center text-white">
        <header className="text-4xl mb-8">Welcome to Our Website</header>
        <p className="text-lg mb-4">
          Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla commodo metus eget libero vehicula, sed hendrerit ipsum vulputate.
        </p>
        <p className="text-lg mb-8">
          Vestibulum ut libero eu justo pretium consectetur.
        </p>
        <button className="bg-blue-500 text-white py-2 px-6 rounded-full hover:bg-blue-600 transition duration-300">
          Get Started
        </button>
        {/* Embed YouTube video */}
        <iframe
          width="560"
          height="315"
          src="https://replit.com/@torcado/SSSPICY"
          title="YouTube video player"
        ></iframe>
      </main>
    </div>
  );
}
