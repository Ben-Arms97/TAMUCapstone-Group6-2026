FROM node:20-alpine

WORKDIR /app

# Prevent native module failures
RUN apk add --no-cache python3 make g++

# Copy dependency manifests
COPY package*.json ./
COPY yarn.lock* ./

# Install dependencies
RUN npm install --legacy-peer-deps

# Copy rest of app
COPY . .

EXPOSE 5173

CMD ["npm", "run", "dev", "--", "--host", "0.0.0.0", "--port", "5173"]