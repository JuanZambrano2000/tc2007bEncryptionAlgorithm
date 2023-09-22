import Link from 'next/link';
import styles from './Navbar.module.css';
import { useState } from 'react'; // Import useState from React

const Navbar = () => {
  // Create a state variable to track hover state
  const [isHovered, setIsHovered] = useState(false);

  // Define the class name for the link based on hover state
  const linkClassName = isHovered ? styles['nav-link-hover'] : '';

  return (
    <nav className="bg-gray-800 p-4">
      <ul className="flex space-x-4 text-white">
        <li>
          {/* Apply the class name to the link */}
          <Link href="/" className={linkClassName} onMouseEnter={() => setIsHovered(true)} onMouseLeave={() => setIsHovered(false)}>Team members</Link>
        </li>
        <li>
          <Link href="/about" className={linkClassName} onMouseEnter={() => setIsHovered(true)} onMouseLeave={() => setIsHovered(false)}>About</Link>
        </li>
        <li>
          <Link href="/services" className={linkClassName} onMouseEnter={() => setIsHovered(true)} onMouseLeave={() => setIsHovered(false)}>Services</Link>
        </li>
        <li>
          <Link href="/contact" className={linkClassName} onMouseEnter={() => setIsHovered(true)} onMouseLeave={() => setIsHovered(false)}>Contact</Link>
        </li>
      </ul>
    </nav>
  );
};

export default Navbar;
