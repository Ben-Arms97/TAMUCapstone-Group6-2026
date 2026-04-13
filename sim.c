#include <stdio.h>
#include <string.h>

#include "mosquitto.h"

int main(void) {
    const char *host = "18.119.164.92";
    int port = 1883;
    const char *client_id = "simdevice";
    const char *topic = "sensors/39-32-30-31-79-30-6f-02/port/1";

    /* Example payload: two raw bytes, 0x00 0x7a */
    unsigned char payload[2];// = {0x00, 0x7a};

    struct mosquitto *mosq = NULL;
    int rc;

    mosquitto_lib_init();

    mosq = mosquitto_new(client_id, true, NULL);
    if (!mosq) {
      fprintf(stderr, "Failed to create mosquitto client\n");
      mosquitto_lib_cleanup();
      return 1;
    }

    rc = mosquitto_connect(mosq, host, port, 60);
    if (rc != MOSQ_ERR_SUCCESS) {
      fprintf(stderr, "Failed to connect: %s\n", mosquitto_strerror(rc));
      mosquitto_destroy(mosq);
      mosquitto_lib_cleanup();
      return 1;
    }

    while (1) {
      printf("> ");
      if (scanf("%hhu %hhu", payload, payload + 1) == EOF) {
        break;
      }

      rc = mosquitto_publish(
          mosq,
          NULL,
          topic,
          sizeof(payload),
          payload,
          0,
          false
          );
      if (rc != MOSQ_ERR_SUCCESS) {
        fprintf(stderr, "Failed to publish: %s\n", mosquitto_strerror(rc));
        continue;
      }

      mosquitto_loop(mosq, 1000, 1);

      printf("Published MQTT message to %s\n", topic);
    }

    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    return 0;
}
