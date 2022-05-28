# UE5SAS3

## List of Features

### Inventory Feature 

Allows to store game items.

**Components:**
- *InventoryActorComponent* - main logic between *InventoryUiActorComponent* and Character. Stores full inventory of obtained items.
- *InventoryUiActorComponent* - ui logic that allows to show inventory items and stores ui widgets for displaying inventory.

### Interaction Feature

Allows player to interact with inventory items(items that might be pick upped) and environment items(levers, chests, etc).

**Components:**
- *InteractionActorComponent* - main login between *InteractionUiActorComponent*, *InventoryActorComponent* and *ObtainedActorComponent*. Stores nearby interactions that player can act. 
- *InteractionUiActorComponent* - ui login that displays nearby interactions.

### Obtainings Feature

Allows player to see obtained items last few seconds.

**Components:**
- *ObtainedActorComponent* - component that displays obtained items last few seconds.
