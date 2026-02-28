import { createRoot } from 'react-dom/client'
import { BrowserRouter, Routes, Route } from "react-router";

import './index.css'
import Layout from './screens/Layout.tsx';
import App from './App.tsx'

createRoot(document.getElementById('root')!).render(
  <BrowserRouter basename='/'>
    <Routes>
      <Route element={<Layout />}>
        <Route path='/' Component={App} />
      </Route>
    </Routes>
  </BrowserRouter>
)
