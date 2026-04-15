# server/Dockerfile
FROM python:3.11-slim

WORKDIR /app

# ---- system deps ----
# - gcc/build-essential often needed for some python wheels
# - postgresql-client gives you "psql" for seeding
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc \
    curl \
    postgresql-client \
    libpcap0.8 \
    tcpdump \
  && rm -rf /var/lib/apt/lists/*

# ---- python deps ----
COPY requirements.txt /app/requirements.txt
RUN pip install --no-cache-dir -r requirements.txt

# ---- app code ----
COPY . /app

# Flask/Gunicorn settings (optional)
ENV PYTHONUNBUFFERED=1
ENV PORT=5000

EXPOSE 5000

# Default command for the server container (init container will override command)
CMD ["gunicorn", "-k", "eventlet", "-w", "1", "-b", "0.0.0.0:5000", "app:app"]
