import { createRoot } from 'react-dom/client'
import { BrowserRouter, Routes, Route } from "react-router";
import { QueryClient, QueryClientProvider } from "@tanstack/react-query";

import './index.css'
import Layout from './screens/Layout.tsx';
import Home from './App.tsx'

const queryClient = new QueryClient();

createRoot(document.getElementById('root')!).render(
  <QueryClientProvider client={queryClient}>
    <BrowserRouter basename='/'>
      <Routes>
        <Route element={<Layout />}>
          <Route path='/' Component={Home} />
        </Route>
      </Routes>
    </BrowserRouter>
  </QueryClientProvider>
)
